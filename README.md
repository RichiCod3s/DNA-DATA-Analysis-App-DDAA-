# DNA-DATA-Analysis-App-DDAA-

Introduction

Direct-to-consumer genetic testing services have exploded in popularity since 
the first autosomal DNA tests for ancestry were offered by the company 
23andme in 2007.

Customers provide a saliva sample that is sent to a laboratory for analysis, 
reports are then generated detailing the customer's ancestry and genetic 
predispositions and finally, the reports are accessed by the customer over the 
web.

In addition to personalized reports from the genetic provider company, the 
customer has access to a raw data file that contains the analysed DNA in the 
form of letters and DNA positions. There are many third-party tools, software 
and DNA upload sites that can interpret the raw data further.
Raw DNA Data File

A sample raw DNA data file called “dnadata.txt” will be provided in advance by 
your facilitator. Raw data files are in a human readable text format, where 
each row represents:

• A DNA position (also called DNA marker)
The marker name typically is a standard name used by researchers to
identify a specific site.

• A Chromosome number
Human chromosome number: A digit from 1 to 6 in our dataset.

• Genomic Location 
Exact genomic location in human genome.

• Customer’s genotype
The specific variants (A, C, G or T) for that marker.


**DDDA**

You have been approached to help build a DNA DATA Analysis software 
application (DDAA) to analyse raw DNA data files. Among the features of the 
DDAA application will be the capability for users to view and search the raw 
data files for information on specific genomic locations.
You are required to implement (using the C programming language) a prototype 
DDAA application. Make use of techniques covered in the course material: 
functions, file handling, dynamic memory allocation, data structures and sorting 
algorithms. 

Question 1 (i): C program [Total: 80 marks]
Create a C program to implement the functions described below. Note that you 
may add your own utility-style functions in addition to each of the functions 
required. Note also that the program should be contained in one file only (i.e. 
no header files or multiple source files). 

Function 1: display_menu [4 marks]
(i) When the application is started, use this function to print a list of options 
to the user using a numbered list. (2 marks)
(ii) When the user selects an option, the system performs the required action, 
and returns to the menu waiting for the user to select another option. For 
any missing or incomplete functions, use a simple print message to 
indicate the name of the function.
Your main menu system should resemble the following:
1. Load RAW DNA data
2. Display RAW Data
3. Count Chromosome Records
4. Display Chromosome Data
5. Sort Chromosome Data
6. Create Chromosome Datafile.
7. Search for DNA at Position
8. Compare Control 
9. Exit System
(2 marks)

Function 2: load_raw_dna_data [8 marks]
(i) Call this function automatically when the program starts. Open a file 
called “dna_data.txt” (the user is not required to input the file name). 
Count the number of records (lines in the file) and display the result 
on screen. (3 marks)
(ii) If the file does not exist, notify the user, and exit the application.
(1 mark)
(iii) Dynamically create sufficient memory for each entry read from the 
file. Also, dynamically create sufficient memory for the rsid property 
of each entry.
Note: Partial marks can be achieved for allocating a fixed size array 
of structs for each entry, and a fixed string size for the rsid property.
Define a struct to represent your DNA at a particular location, 
containing the following fields:
rsid (char [])
chromosome (int)
position (long)
allele1 (char)
allele2 (char)
(4 marks)

Function 3: display_raw_data [8 marks]
(i) When the user selects the “Display Raw Data” menu item, display
the raw data records on screen. (3 marks)
(ii) Display 40 records at a time on screen. (3 marks)
(iii) Display the information with headers and formatting, not simply a list 
of raw information. (2 marks)
Function 4: count_chromosome_records [8 marks]
When the user selects the “Count Chromosome Records” menu item, the 
system prompts the user for a chromosome number. Then the application 
counts the total number of records stored in its memory for that chromosome 
and outputs the value to the screen. 
Function 5: display_chromosome_data [8 marks]
When the user selects the “Display Chromosome Data” menu item, the system 
prompts the user for a chromosome number. Then the application displays the 
records stored in its memory for that chromosome. 

Function 6: sort_chromosome_data [12 marks]
(i) When the user selects the “Sort Chromosome Data” menu item, the 
system prompts the user for a chromosome number. Then the 
application should order all records with that chromosome number 
starting with the highest value of position. (5 marks)
(ii) Make a copy of the original array of transactions to perform the 
sorting function - the sorted records should be stored in an array 
named “chromosome_data”. Make sure that the sorted information is 
displayed on screen in a report with headers, not simply a list of raw 
information.

Function 7: create_chromosome_file [8 marks]
When the user selects the “Create Chromosome Datafile” menu item, the 
system should output the contents of the “chromosome_data” array (if it 
contains records) mentioned in function 6 to a file. The file should be named 
“chromosomeN_position_data.txt” – where N was the chromosome number 
chosen in function 6. 

Function 8: search_rsid [8 marks]
When the user selects the “Search DNA at position” menu item, the user is 
prompted for an rsid value, the application then outputs the Allele values at that 
rsid location.

Function 9: compare_control [12 marks]
When the user selects the “Compare Control” menu item, the user is prompted 
for three combinations of rsid and allele1 and allele2 values as displayed below. 
If each of the rsid and corresponding allele values are found then the system 
outputs a success message to the screen indicating that the control was found 
and the chromosome number.
Please Enter Control Values that you wish to compare:
rs719065 GG
rs6596796 GG
rs2281351 GG
Congratulations! Found GGGGGG on Chromosome 6!

Function 10: exit_DDAA [4 marks]
(i) Close the program whenever the user chooses “Exit System” from 
the menu. (1 marks)
(ii) Ensure chromosome data is saved. (2 marks)
(iii) Ensure all opened files are closed. (1 mark)

