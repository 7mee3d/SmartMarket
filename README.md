# 🛒 SuperMark Project

A simple and beginner-friendly **C++ Supermarket System** that simulates basic shopping and management operations through a console-based interface. The project uses clear menus, simple file handling, and structured code to help users and managers perform tasks like viewing products, placing orders, and managing inventory. Ideal for C++ learners to practice file I/O, menu navigation, and structured programming.


---

## 🧾 Main Features

### 👤 User Section:
- View all available products.
- Purchase a product by entering its ID.
- Display invoice (shows purchased products with total cost).
- Clear current order.

### 👨‍💼 Manager Section:
- *(To be developed or can be added based on requirements.)*

---

## 💾 File Usage
- **Prodects.txt**: Stores product details (ID, name, price).
- **Reciept.txt**: Stores the receipt of the user's purchase.

---

## 📋 Internal Structure
- Uses `struct` to manage product data.
- Organized screens using custom header/footer display functions.
- `enum` used for menu option selection.
- Tables formatted using `iomanip` for better readability.

---

## ✅ How to Run
1. Compile the project using any C++ compiler (g++, Visual Studio, etc.).
2. Make sure `Prodects.txt` exists in the project directory.
3. Run the executable and follow the on-screen instructions.

---

## ✨ Notes
- Special attention was given to screen formatting for better user experience.
- All interface sections are modular and cleanly separated.
- Best run on Windows environments due to usage of `system("cls")`.

---

## 📌 Author
- This project was developed for educational purposes and to practice file handling and text-based UI in C++.
