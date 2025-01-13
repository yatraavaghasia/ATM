## ATM Cash Dispenser and Deposit System in C++

This C++ code simulates a basic ATM cash dispenser and deposit system. It utilizes two classes:

* **Cash:** Represents the cash denominations (rupee notes) available in the ATM and the number of notes for each denomination.
* **ATM:** Manages the ATM's functionalities, including:
    * Initialization by reading cash information from a file ("cash.txt").
    * Displaying available notes.
    * Dispensing cash based on a requested withdrawal amount, considering available notes.
    * Depositing new notes of various denominations.
    * Updating the ATM's cash state after each transaction (dispense or deposit) by writing to the "cash.txt" file.

## Running the Code

**Prerequisites:**

* C++ compiler (e.g., GCC)
* Text editor or IDE (e.g., Visual Studio Code)

**Steps:**

1. **Create a C++ file:** Save the code provided above as a `.cpp` file (e.g., `atm.cpp`).
2. **Create a data file (optional):** Create a text file named "cash.txt" in the same directory as your `.cpp` file. This file should contain the initial ATM cash state in the format:

   ```
   denomination:number_of_notes
   ```

   For example:

   ```
   500:10
   200:5
   100:20
   ...
   ```

3. **Compile and run:**
   * **Using a terminal:**
      * Open a terminal in the directory containing your `.cpp` file.
      * Compile the code using a command like:

         ```bash
         gcc atm.cpp -o atm  
         ```

      * Run the executable:

         ```bash
         ./atm
         ```

   * **Using an IDE:**
      * Follow your IDE's specific instructions for compiling and running C++ programs. Many IDEs offer built-in functionality for these steps.

The program will simulate ATM operations like displaying available notes, dispensing cash (considering available notes), depositing new notes, and updating the ATM's cash state.
