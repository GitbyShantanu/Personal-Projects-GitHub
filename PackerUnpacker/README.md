# Packer-Unpacker Project 🚀

### 📌 Project Description

**Packer-Unpacker** is an innovative **file archiving tool** crafted using **Core Java**, designed to seamlessly bundle multiple text files into a single archive and extract them back with precision. This project showcases the power of **file handling, metadata management**, and **command-line interaction** in Java, making it a practical solution for file storage optimization.

---

## 🔑 Key Features

- Effortlessly pack multiple text files into a unified archive.
- Custom file headers to **preserve filename and size metadata**.
- Restore files to their **original structure without data loss**.
- Simplified **CLI-based interaction** for efficient operation.
- Modular and clean codebase following **OOPS principles**.

---

## 📂 Folder Structure

```
PackerUnpacker
├── bin                        # Compiled class files (Initially Empty)
├── sample_files               # Sample input text files
└── src
    └── main
        └── java
            └── packerunpacker
                ├── Main.java          # Entry Point of the Application
                ├── Packer.java       # Core File Packing Logic
                └── Unpacker.java     # File Unpacking and Restoration Logic
```

---

## 🔥 How It Works

### Packer

- Accepts the **folder path** as input.
- Iterates through each `.txt` file in the folder.
- Extracts file metadata like **filename and size**.
- Appends metadata headers before file content.
- Combines all files into a **single packed file**.

### Unpacker

- Reads the packed file line-by-line.
- Extracts metadata headers.
- Splits content into individual files.
- Restores files with their **original filenames and sizes**.

---

## 🎯 How to Run the Project

1. **Navigate to the Project Directory**

```bash
cd Personal-Projects-GitHub/PackerUnpacker
```

2. **Compile the Project**

```bash
javac -d bin src/main/java/packerunpacker/*.java
```

3. **Navigate to bin Directory**

```bash
cd bin
```

4. **Packing Files**

```bash
java packerunpacker.Main -pack ../sample_files PackedData.txt
```

5. **Unpacking Files**

```bash
java packerunpacker.Main -unpack PackedData.txt
```

---

## 📌 Sample Output

```
🔄 Packing Process Started...
✅ File Packed: file1.txt | Size: 1024 bytes
✅ File Packed: file2.txt | Size: 2048 bytes
🎯 Packing Completed Successfully!

🔓 Unpacking Process Started...
✅ File Restored: file1.txt | Size: 1024 bytes
✅ File Restored: file2.txt | Size: 2048 bytes
🎯 Unpacking Completed Successfully!
```

---

## 🔑 Technology Stack

| Component      | Description              |
|---------------|--------------------------|
| Language      | **Java (JDK 11+)**      |
| Core Concepts | File Handling, OOPS, CLI |
| IDE           | IntelliJ IDEA / VSCode   |

---

## 🎯 Future Scope

- Adding **folder-level packing support**.
- Implementing **multithreading** for faster operations.
- Integrating **compression algorithms** to minimize archive size.
- Developing a **GUI-based interface** using Swing or JavaFX.

---

## 👤 Author

**Shantanu**  
GitHub: [GitbyShantanu](https://github.com/GitbyShantanu)  

---

## 💪 Conclusion

The **Packer-Unpacker Project** is a testament to the power of **Core Java's file handling capabilities**. It offers a solid foundation for understanding file archiving, metadata preservation, and command-line-based applications — making it an essential stepping stone for mastering system-level projects.

---

### 🔥 Show Your Support

If this project added value to your learning journey, don't forget to **star the repository ⭐** on GitHub and share your feedback!

