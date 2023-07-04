import { useEffect, useState } from "react";
import reactLogo from "./assets/react.svg";
import { invoke } from "@tauri-apps/api/tauri";
import "./App.css";

function App() {
  const [resultMsg, setResultMsg] = useState("");
  const [apiVersion, setApiVersion] = useState("");
  const [a, setA] = useState("");
  const [b, setB] = useState("");

  async function greet() {
    // Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
    setResultMsg(await invoke("greet", { a,b }));
  }

  async function getApiVersion() {
    // Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
    setApiVersion(await invoke("get_api_version"));
  }

  useEffect(() =>{
    getApiVersion();

  },[]);
  
  return (
    <div className="container">
      <div className="main-content">
        <h1>Welcome to Tauri!</h1>

        <div className="row">
          <a href="https://vitejs.dev" target="_blank">
            <img src="/vite.svg" className="logo vite" alt="Vite logo" />
          </a>
          <a href="https://tauri.app" target="_blank">
            <img src="/tauri.svg" className="logo tauri" alt="Tauri logo" />
          </a>
          <a href="https://reactjs.org" target="_blank">
            <img src={reactLogo} className="logo react" alt="React logo" />
          </a>
        </div>

        <p>Click on the Tauri, Vite, and React logos to learn more.</p>

        <form
          onSubmit={(e) => {
            e.preventDefault();
            greet();
          }}
        >
          <div className="col">
            <input
              id="a-input"
              onChange={(e) => setA(e.currentTarget.value)}
              placeholder="Enter a..."
            />
            <input
              id="b-input"
              onChange={(e) => setB(e.currentTarget.value)}
              placeholder="Enter b..."
            />
            <button type="submit">Calculate(add)</button>
          </div>
        </form>

        <p>{resultMsg}</p>
      </div>
      <footer className="footer">
        API Version: {apiVersion}
      </footer>
    </div>
  );
}

export default App;
