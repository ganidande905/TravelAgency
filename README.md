# 🏝️ Tour Booking CLI System  

A **C language-based command-line application** for managing **tour bookings** with **Role-Based Access Control (RBAC)**. Built as a **college project**, this system allows **admins, agents, and customers** to interact with the booking system securely through a terminal interface.

---

## 📌 Features  
✅ **Role-Based Access Control (RBAC)** – Users have different permissions based on their roles  
✅ **User Authentication & Authorization** – Secure login system with different privileges  
✅ **Tour Package Management** – Add, update, delete, and view available tours  
✅ **Booking Management** – Customers can book, modify, and cancel tours  
✅ **Agent Functionality** – Agents can manage customer bookings and assist with reservations  
✅ **Admin Controls** – Manage users, agents, and tour listings  
✅ **Command-Line Interface (CLI)** – Runs directly in the terminal for efficient operation  

---

---

## 👥 User Roles & Permissions  

| Role      | Permissions |
|-----------|------------|
| **Admin**  | Manage users, add/edit/remove tours, view all bookings |
| **Agent**  | Manage customer bookings, assist in modifying reservations |
| **Customer** | Browse tours, book trips, modify/cancel own bookings |

---

## How to run

```
make clean
make
```