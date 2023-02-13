# Bubble-Sort-Application

The code is a program that sorts medical records of patients in ascending or descending order based on the user's input. The program starts by including libraries such as iostream, cstring, and iomanip, all of which are required for input/output operations and string manipulations.

The code then defines several arrays and constants, including the number of patients (NUM_PATIENTS), the maximum length of a name (MAX_NAME_LENGTH), and the length of the patient's ID (ID_LENGTH). The arrays store information about each patient's age, ID number, first and last name, and sex.

In the first part of the program, the user is prompted to enter the sorting category. The user can choose to sort the records by age, ID, first name, last name, or sex. The program uses the do-while loop to ensure that the input is valid and will keep prompting the user to enter the sorting category until a valid input is provided. The program also converts the user's input to lowercase and compares it with the predefined strings such as "age", "id", "first", "last", and "sex". If a match is found, the program displays a message indicating the sorting category and breaks out of the loop. If no match is found, the program will display an error message and prompt the user to enter the sorting category again.

In the next part of the program, the records are sorted based on the user's input. If the user chose to sort the records by age, the program uses a for loop and the if statement to compare each element in the age array with the next one. If the current element is greater than the next one, the two elements are swapped. The loop continues until the age array is sorted in ascending or descending order.

Similarly, if the user chose to sort the records by ID, first name, last name, or sex, the program will use the same sorting technique as mentioned above.

Finally, the program displays the sorted records in a tabular format, showing the patient's ID, name, age, and sex.
