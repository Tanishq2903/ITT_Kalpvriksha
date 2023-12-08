import './App.css';
import { BrowserRouter as Router, Routes, Route } from "react-router-dom"
import header from './Components/header/Header';
import Home from './pages/home/home';
import movieList from './Components/movieList/MovieList';
import Movie from './pages/movieDetail/movie';

function App() {
  return (
    <div className="App">
        <Router>
          <header/>
            <Routes>
                <Route index element={<Home />}></Route>
                <Route path="movie/:id" element={<Movie />}></Route>
                <Route path="movies/:type" element={<movieList />}></Route>
                <Route path="/*" element={<h1>Error Page</h1>}></Route>
            </Routes>
        </Router>
    </div>
  );
}

export default App;
