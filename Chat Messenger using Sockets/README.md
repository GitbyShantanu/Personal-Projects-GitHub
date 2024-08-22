# Chat Messenger Project

## 📚 Overview

This project is a simple Chat Messenger application implemented in Java. It demonstrates how to establish a TCP connection between a client and a server using sockets. The client can send messages to the server, and the server responds back, allowing a basic two-way communication.

## 🌟 Features

- **Client-Server Architecture**: The project showcases a robust client-server architecture using Java Sockets.
- **Bi-directional Communication**: The client and server can exchange messages in real-time.
- **Graceful Termination**: The client can terminate the chat by sending the message `"end"`.
- **Connection Handling**: Both the client and server check if the connection is successfully established.

## 🗂️ Project Structure

- **Client Code**: The client-side code (`Client.java`) handles sending messages to the server and receiving responses.
- **Server Code**: The server-side code (`Server.java`) listens for client connections, receives messages, and sends responses.

## 🛠️ Prerequisites

- Java Development Kit (JDK) installed on your system.
- Basic knowledge of Java programming.
- Understanding of TCP/IP socket programming.

## 🚀 How to Run

### 🖥️ Server

1. Compile the server code:

   ```bash
   javac Server.java
   ```

2. Run the server code:

   ```bash
   java Server
   ```

3. The server will start listening on port `2100` and wait for a client connection.

### 💻 Client

1. Compile the client code:

   ```bash
   javac Client.java
   ```

2. Run the client code:

   ```bash
   java Client
   ```

3. Once the client starts, it will attempt to connect to the server at `localhost` on port `2100`.
4. Upon a successful connection, you can start typing messages to send to the server.
5. To terminate the chat, type `"end"` and press Enter.

## 📜 Code Explanation

### Client Code (`Client.java`)

- **Socket Creation**: 
  ```java
  Socket sobj = new Socket("localhost", 2100);
  ```
  The client creates a socket to connect to the server on `localhost` at port `2100`.

- **Communication Streams**:
  - `PrintStream ps`: Used to send data (messages) to the server.
  - `BufferedReader br1`: Reads the server's response.
  - `BufferedReader br2`: Reads the user's input from the console.

- **Chat Loop**:
  The client enters a loop where it continuously reads user input and sends it to the server. It waits for a response from the server and displays it.

- **Graceful Termination**:
  The client checks if the user input is `"end"`. If so, it breaks the loop, closes all streams, and terminates the connection.

### Server Code (`Server.java`)

- **Server Socket Creation**:
  ```java
  ServerSocket ssobj = new ServerSocket(2100);
  ```
  The server creates a `ServerSocket` to listen for client connections on port `2100`.

- **Client Connection**:
  ```java
  Socket sobj = ssobj.accept();
  ```
  The server accepts the connection from the client, establishing a successful link.

- **Communication Streams**:
  - `PrintStream ps`: Used to send data (messages) to the client.
  - `BufferedReader br1`: Reads the client's messages.
  - `BufferedReader br2`: Reads the server's input from the console.

- **Chat Loop**:
  The server enters a loop where it continuously reads the client's messages and sends responses back. If the client's message is `null`, the loop breaks, ending the chat session.

## 📝 Sample Output

### Server
```bash
---------------------------------------------------------------
Server of Chat Messenger is running...

Server is in Listening mode at port : 2100
Client and server connection is successful.

Chat Messenger is started...

Client says : Hello Server!
Enter message for Client : Hello Client!
Client says : How are you?
Enter message for Client : I am good, thank you!

Thank you for using Chat Messenger...
---------------------------------------------------------------
```

### Client
```bash
---------------------------------------------------------------
Client of Chat messenger is running...

Client is waiting for server to accept the request..
Client and server connection is successful.

Chat Messenger is started...

Enter message for server:
Hello Server!
Server says: Hello Client!
Enter message for server:
How are you?
Server says: I am good, thank you!
Enter message for server:
end

Thank you for using Chat Messenger...
---------------------------------------------------------------
```

## 🎯 Conclusion

This project is a great way to learn about socket programming in Java. It provides a foundational understanding of how client-server communication works, making it a valuable addition to your portfolio. The simplicity and clarity of the code make it easy for others to understand and appreciate your work.

## 🔮 Future Enhancements

- **🖼️ GUI Implementation**: Consider adding a graphical user interface to enhance user experience.
- **🔄 Multi-Client Support**: Extend the server to handle multiple clients simultaneously.
- **🔒 Encryption**: Implement message encryption for secure communication.

---

Thank you for reviewing the Chat Messenger project! Your feedback and suggestions are highly appreciated. 😊