Student: José Joaquim da Silva Neto 
RN: 22.221.013-0

INSTRUCTIONS

To run the project, follow these steps:
1 - run the file "main.c"
2 - register all the information you deem necessary for the financial manager.
3 - after registering the information and closing the code "main.c", open the file "index.html" located in the folder "paginaHTML"
4 - browse the site, viewing the extracts, the Home page and the developers page.

REQUIREMENTS

Mandatory Features
a) Record of income and expenses with values, descriptions and dates;
b) Categorize the movements, such as: Housing, Studies, Transport, Food, Work;
c) Transaction report for the last 12 months.
d) Transaction report for each category for the last month.
e) Creation of at least 2 header .h files
f) Implement file reading routine
g) Creation of at least two data structures of the “struct” type
h) Use at least 3 variables of the “define” type
i) Use in at least two situations the dynamic allocation of vector or matrices

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

Extra Functionality
a) Instantiate the project on github, considering good development practices
b) Integration with GNUPLOT
c)Files with execution logs that MAKE SENSE.

a) main.c file, line 565 is commenting out a link to the git hub repository where the project is instantiated.

Bonus Functionality
a) Integration with an HTML page, which interacts with the user and presents the results of transactions, balances and/or statements.
b) Visual presentation of results through graphics
c) Use of more elaborate data structures such as lists, queues, stacks, trees and graphs.

a) The index.html file is part of the project, interacting with the user and presenting the results of the movements.
