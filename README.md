# Financial-Manager

## ℹ️ Description

The Financial Manager is the semi-annual project of the `Algorithm Development` subject (C).<br>
Coded in 2022.1 at the [FEI](https://portal.fei.edu.br/) college, located in São Bernardo do Campo/SP/BR.<br>
The project was done in pairs, but one of the members preferred to remain anonymous in this repository.<br>

⚠️Some of the code and other parts may be in Portuguese, work in progress for English.

---

## 📝 Instructions

To run the project, follow these steps:<br>
1 - run the file "main.c"<br>
2 - register all the information you deem necessary for the financial manager.<br>
3 - after registering the information and closing the code "main.c", open the file "index.html" located in the folder "paginaHTML"<br>
4 - browse the site, viewing the extracts, the Home page and the developers page.<br>

---


## 🛠️ **Technologies**

![HTML Badge](https://camo.githubusercontent.com/c8d13e1c596a6726b1da8475a9299fac133f95ef009083b48be01f975a44987e/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f2d48544d4c2d3035313232413f7374796c653d666c6174266c6f676f3d48544d4c35) 
![CSS Badge](https://camo.githubusercontent.com/d738d76484d50c8345c2d01e39364b707285bc7936140858e7909dfe6424efb2/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f2d4353532d3035313232413f7374796c653d666c6174266c6f676f3d43535333266c6f676f436f6c6f723d313537324236) 
![C Badge](https://camo.githubusercontent.com/d85743d50d2150d990e65031be13d21bbb79de159cb06c81d049561faf7cdcba/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f2d432d3035313232413f7374796c653d666c6174266c6f676f3d43)

---

## 📃 Obligations

Mandatory Features<br>
a) Record of income and expenses with values, descriptions and dates;<br>
b) Categorize the movements, such as: Housing, Studies, Transport, Food, Work;<br>
c) Transaction report for the last 12 months.<br>
d) Transaction report for each category for the last month.<br>
e) Creation of at least 2 header .h files<br>
f) Implement file reading routine<br>
g) Creation of at least two data structures of the “struct” type<br>
h) Use at least 3 variables of the “define” type<br>
i) Use in at least two situations the dynamic allocation of vector or matrices<br>

a) Main.c file, from line 93 (in this function, the income is registered), from line 177 (in this function, expenses are registered). Both with values, descriptions and dates.
- It is possible to validate this registration on lines 137 and 140 (expenses)
- On lines 240, 245 and 249 it is possible to validate the registration of the expense "House"
- (we only put an example of the expense, since the others have similar logic and they are found in the following "else if")

b) Main.c file, line 177 (in this function, expenses are registered and transactions are categorized)
- In this function, from line 228 to line 325, there is a series of "if" and "else if" that determine which txt file the movement will be registered in
- In line 228 the "if(tipo_gasto==1)" is responsible for registering the transactions of the "housing" type

c) Main.c file, line 516 (in this function you can see the annual report)
- the function uses a "while" on line 537 to print each line of the txt file

d) Main.c file, line 386 (function responsible for performing item d), line 414 and 493 (types of expenses, a series of conditions to determine which report will be shown)
- In line 414 "if(tipo_gasto==1)" this "if" is responsible for printing the housing report
- (we only put an example of the report, since the others have similar logic and they are found in the following "else if")

e) Main.c file, lines 7 and 8 (header.h files);

f) File main.c, line 432 (an example of reading files, where study.txt is read);
- (all our project is using files for its operation)

g) Main.c file, lines 21, 30 and 41 (three "struct" structures);

h) File main.c, line 10, 11, 12 (variables of type Define);

i) Main.c file, lines 100 and 101 and 184 and 185 (situations where dynamic allocation was used);
- the vector was used in lines 124 and 219
- dynamic allocation was also used in structs line 112 and 210

Extra Functionality<br><
a) Instantiate the project on github, considering good development practices<br>
b) Integration with GNUPLOT<br>
c)Files with execution logs that MAKE SENSE.<br>

a) main.c file, line 565 is commenting out a link to the git hub repository where the project is instantiated.<br>

Bonus Functionality<br>
a) Integration with an HTML page, which interacts with the user and presents the results of transactions, balances and/or statements.<br>
b) Visual presentation of results through graphics<br>
c) Use of more elaborate data structures such as lists, queues, stacks, trees and graphs.<br>

a) The index.html file is part of the project, interacting with the user and presenting the results of the movements.<br>

---

Made by [**Ze Neto**](https://github.com/zejsneto/) 
