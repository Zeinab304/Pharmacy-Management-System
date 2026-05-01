# 💊 Pharmacy Management System

A robust and efficient CLI application developed in **C** to streamline pharmacy inventory and sales management. This project focuses on high performance and effective resource management through the use of **Dynamic Memory Allocation**.

## ✨ Key Features
* **Inventory Management:** Add new medicines, update prices, and replenish stock levels.
* **Sales System:** Process transactions, generate total bills, and automatically deduct quantities from the stock.
* **Smart Search:** Quickly locate specific medicine details using a unique **ID**.
* **Low Stock Alerts:** A dedicated reporting tool that identifies items with fewer than 5 units remaining.
* **Dynamic Scaling:** Automatically expands inventory capacity using `realloc` as more data is added.
* **Memory Efficiency:** Implements proper memory management by utilizing `malloc` for strings and arrays, with a full cleanup (`free`) upon exit.

## 🛠 Technical Implementation
This system leverages core programming concepts to ensure reliability:
* **Custom Data Structures:** Uses `typedef struct` to manage complex medicine attributes like names, IDs, prices, and quantities.
* **Dynamic Memory:** Employs pointers and manual memory management for flexible data handling.
* **Modular Design:** Organized into clear functions for seeding data, selling, updating, and reporting.

## 📂 Project Structure
* `main.c`: The core source code containing the logic and functionality.
* `Pharmacy Management System.cbp`: The project configuration file for the **Code::Blocks** IDE.
