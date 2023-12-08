import { useState } from 'react'
import viteLogo from '/vite.svg'
import './App.css'
import Card from './Components/Card'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
     
      <Card user={"tanishq"}/>
      <Card user={"tanisha"}/>
      <Card/>
      
    </>
  )
}

export default App
