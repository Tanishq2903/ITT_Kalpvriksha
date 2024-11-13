from flask import Flask, render_template, request, redirect, url_for
import sqlite3

app = Flask(__name__)

# Database initialization
conn = sqlite3.connect('bookstore.db')
cursor = conn.cursor()

# Create tables
cursor.execute('''
    CREATE TABLE IF NOT EXISTS authors (
        author_id INTEGER PRIMARY KEY,
        author_name TEXT
    )
''')

cursor.execute('''
    CREATE TABLE IF NOT EXISTS categories (
        category_id INTEGER PRIMARY KEY,
        category_name TEXT
    )
''')

cursor.execute('''
    CREATE TABLE IF NOT EXISTS books (
        book_id INTEGER PRIMARY KEY,
        title TEXT,
        author_id INTEGER,
        category_id INTEGER,
        price REAL,
        quantity_in_stock INTEGER,
        FOREIGN KEY (author_id) REFERENCES authors(author_id),
        FOREIGN KEY (category_id) REFERENCES categories(category_id)
    )
''')

cursor.execute('''
    CREATE TABLE IF NOT EXISTS orders (
        order_id INTEGER PRIMARY KEY,
        book_id INTEGER,
        quantity INTEGER,
        total_price REAL,
        FOREIGN KEY (book_id) REFERENCES books(book_id)
    )
''')

# Insert sample data
cursor.executemany('INSERT INTO authors (author_name) VALUES (?)', [('Author 1',), ('Author 2',), ('Author 3',)])
cursor.executemany('INSERT INTO categories (category_name) VALUES (?)', [('Fiction',), ('Non-Fiction',), ('Science Fiction',)])
cursor.executemany('''
    INSERT INTO books (title, author_id, category_id, price, quantity_in_stock)
    VALUES (?, ?, ?, ?, ?)
''', [
    ('Book 1', 1, 1, 19.99, 100),
    ('Book 2', 2, 2, 24.99, 50),
    ('Book 3', 3, 3, 29.99, 75),
])

# Commit changes and close connection
conn.commit()
conn.close()

# Routes
@app.route('/')
def index():
    conn = sqlite3.connect('bookstore.db')
    cursor = conn.cursor()

    # Fetch books with their authors and categories
    cursor.execute('''
        SELECT books.book_id, books.title, authors.author_name, categories.category_name, books.price, books.quantity_in_stock
        FROM books
        JOIN authors ON books.author_id = authors.author_id
        JOIN categories ON books.category_id = categories.category_id
    ''')
    books = cursor.fetchall()

    conn.close()

    return render_template('index.html', books=books)

@app.route('/add_to_cart/<int:book_id>')
def add_to_cart(book_id):
    conn = sqlite3.connect('bookstore.db')
    cursor = conn.cursor()

    # Fetch selected book
    cursor.execute('SELECT * FROM books WHERE book_id = ?', (book_id,))
    book = cursor.fetchone()

    # Close the connection
    conn.close()

    return render_template('add_to_cart.html', book=book)

@app.route('/place_order', methods=['POST'])
def place_order():
    if request.method == 'POST':
        book_id = request.form['book_id']
        quantity = int(request.form['quantity'])

        conn = sqlite3.connect('bookstore.db')
        cursor = conn.cursor()

        # Fetch book details
        cursor.execute('SELECT * FROM books WHERE book_id = ?', (book_id,))
        book = cursor.fetchone()

        # Calculate total price
        total_price = quantity * book[4]  # price is at index 4 in the books tuple

        # Insert order into the database
        cursor.execute('INSERT INTO orders (book_id, quantity, total_price) VALUES (?, ?, ?)', (book_id, quantity, total_price))

        # Update stock quantity
        new_quantity = book[5] - quantity  # quantity_in_stock is at index 5 in the books tuple
        cursor.execute('UPDATE books SET quantity_in_stock = ? WHERE book_id = ?', (new_quantity, book_id))

        # Commit changes and close connection
        conn.commit()
        conn.close()

        return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
