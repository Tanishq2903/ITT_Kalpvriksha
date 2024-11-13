import { useState } from "react";




function App() {
  let [counter,setCounter] = useState(12)

const addBy = () =>{
  counter = counter+1
setCounter(counter)
console.log("clicked",counter)
}
const decreaseBy = () =>{
  counter = counter-1
setCounter(counter)
  console.log("clicked",counter)
}
  return (
    <>
    <h1>Number : {counter}</h1>
    <button onClick={addBy}>Increase</button>
    <br></br>
    <br></br>
    <button onClick={decreaseBy}>Decrease</button>
    </>
   
     
  )
}

export default App
