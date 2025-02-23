
# 📝 **get_next_line - 1337 School Project**

Welcome to my **get_next_line** repository! 🚀  
The **get_next_line** project at **1337 School** was a critical exercise in mastering **file handling** and **buffer management** in C. The goal was to create a function that reads a line from a file descriptor, which may be a file, a socket, or the standard input, and handles various edge cases such as multiple lines, large files, and memory management.

---

## 📊 **Project Overview**

The **get_next_line** project involves implementing a function that reads one line at a time from a file descriptor. This project focuses on handling buffers, dynamic memory allocation, and string manipulation.

---

## 🔧 **Functions Implemented**

- **get_next_line()**: The main function that reads one line at a time from a file descriptor.
- **ft_strdup()**: A helper function that duplicates a string.
- **ft_strjoin()**: A helper function that joins two strings.
- **ft_strchr()**: A helper function that locates the first occurrence of a character in a string.
- **ft_strlen()**: A helper function that calculates the length of a string.

---

## 📋 **Project Structure**

The project is structured as follows:

```
get_next_line/
│
├── src/              # Source files for the project
│   ├── get_next_line.c   # Main implementation of get_next_line()
│   ├── get_next_line_utils.c  # Utility functions
│
├── include/          # Header files
│   └── get_next_line.h   # Header file with function prototypes
│
├── Makefile          # Makefile to compile the project
└── README.md         # Project documentation
```

---

## 📂 **Usage**

To use the **get_next_line** function, include the header file `get_next_line.h` and compile the source files along with your main program. Here's an example of how to use the function:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("Line: %s
", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 🛠️ **Installation**

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/samir-ouaammou/1337-Get_next_line
   ```

2. Navigate to the project directory:
   ```bash
   cd 1337-Get_next_line/Projects
   ```

3. Compile the source files using `make`:
   ```bash
   make
   ```

4. Clean up compiled files:
   ```bash
   make clean
   ```

5. To remove all object files and the executable:
   ```bash
   make fclean
   ```

6. To recompile the project from scratch:
   ```bash
   make re
   ```

---

## 🎯 **Challenges Overcome**

During this project, I faced and overcame challenges such as:
- **Handling buffers**: I had to efficiently manage buffers and ensure no data was lost between reads.
- **Dynamic memory allocation**: Implementing functions that allocated memory dynamically while avoiding memory leaks.
- **Edge cases**: Ensuring that the function handled multiple newlines, empty lines, and the end of a file correctly.

---

## 🏆 **Key Achievements**

- Mastered **file handling** and **buffer management** in C.
- Gained experience in **dynamic memory allocation** and **string manipulation**.
- Successfully tackled various edge cases like reading empty lines and handling large files.

---

## 🚀 **Next Steps**

With **get_next_line** completed, I am now focused on:
- Implementing more advanced projects like **libft**, **ft_printf**, and **Born2beroot**.
- Further refining my understanding of **file I/O**, **memory management**, and **system-level programming**.

---

## 🌟 **Reflection**

The **get_next_line** project taught me the importance of **efficient memory management** and how to handle **file I/O** in C. It was a rewarding experience that allowed me to improve my understanding of how programs interact with the system at a low level. I am excited to apply these concepts in future projects.

---

Thank you for checking out my **get_next_line** project! 🚀 Stay tuned for more updates as I continue to enhance my skills and tackle new challenges.
