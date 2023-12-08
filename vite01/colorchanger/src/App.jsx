import { useState } from "react";

function App() {
  const [color, setColor] = useState("olive");

  return (
    <div
      className="flex flex-wrap w-full h-screen justify-center"
      style={{ backgroundColor: color }}
    >
    <h1 className="text-lg text-white font-semibold p-80">click on button to change the background colours </h1>
      <div className="fixed flex flex-wrap justify-center bg-white bottom-12" >
        <button onClick={()=>setColor("brown")}
        className="outline-none text-white px-4 py-1 rounded-xl shadow-lg space-y-2"
        style={{backgroundColor:"black"}}
        >brown</button>
         <button onClick={()=>setColor("yellow")}
         className="outline-none text-white px-4 py-1 rounded-xl shadow-lg space-y-2"
         style={{backgroundColor:"black"}}
        >yellow</button>
         <button onClick={()=>setColor("red")}
         className="outline-none text-white px-4 py-1 rounded-xl shadow-lg space-y-2"
         style={{backgroundColor:"black"}}
        >red</button>
         <button onClick={()=>setColor("#bd8699")}
         className="outline-none text-white px-4 py-1 rounded-xl shadow-lg space-y-2"
         style={{backgroundColor:"black"}}
        >pink</button>
         <button onClick={()=>setColor("black")}
         className="outline-none text-white px-4 py-1 rounded-xl shadow-lg space-y-2"
         style={{backgroundColor:"black"}}
        >black</button>
      </div>
    </div>
  );
}

export default App;
