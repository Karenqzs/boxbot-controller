class ControlComponent extends React.Component {
  constructor(props) {
    super(props);    
    
    // make a websocket connection to the server we loaded this page from.
    this.socket = new WebSocket(`ws://${window.location.host}/comm`);
    
    // when the socket closes, issue an alert.
    this.socket.addEventListener('close', () => {
      alert("Socket connection to server closed.");
    });
    
    // when there's a message from the server, use the handleMessage function
    // to handle it.
    this.socket.addEventListener('message', message => {
      this.handleMessage(message);
    })
  }
  
  handleMessage(message) {
    console.log("Message:", message.data);
    // do something with this data?
  }
  
  sendMessage(message) {
    // send the message to the server over the websocket.
    this.socket.send(message);
  }
  
  render() {
    // four buttons. see index.html for styling.
    return <div className="wrapper">
       <button onClick={() => this.sendMessage("left signal")}>left turn</button><button onClick={() => this.sendMessage("right signal")}>right turn</button><br />
        <button onClick={() => this.sendMessage("forward")}>Fwd</button><br />
        <button onClick={() => this.sendMessage("left")}>Left</button> <button onClick={() => this.sendMessage("halt")}>halt</button> <button onClick={() => this.sendMessage("right")}>Right</button><br />
        <button onClick={() => this.sendMessage("reverse")}>Back</button><br />
        <button onClick={() => this.sendMessage("dance")}>Dance</button><br />
        <button onClick={() => this.sendMessage("set speed 1")}>1</button><button onClick={() => this.sendMessage("set speed 2")}>2</button><button onClick={() => this.sendMessage("set speed 3")}>3</button>
        
        
       
        
      </div>
  }
}

// render that control component, defined above, into the "root" element of index.html
ReactDOM.render(
  <ControlComponent />,
  document.getElementById('root')
);

