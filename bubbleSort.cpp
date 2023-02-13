// Include screen I/O libraries
#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 

int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    int idnum[] = {10854893, 10983922, 98333894, 57290888, 14899822, 79278282, 44293822, 62911023, 28399020, 33212322}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient


    // PART 1: Select a primary sorting category from user input
    char input_string[5]{}; // user enters input in this string
    char age_string[]{"age"};
    char id_string[]{"id"};
    char frn_string[]{"first"};
    char lsn_string[]{"last"};
    char sex_string[]{"sex"};
    bool invalidinput = 1; // condition for iterating the do-while loop
        
        // user enters input
        cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";
        cin >> input_string;

        do{
            invalidinput == 0;

            // the loop converts all the characters entered to lowercase.
            for (int i = 0; i < strlen(input_string); i++){

                if(input_string[i] >= 65 && input_string[i] <= 90){
                    input_string[i] = input_string[i] + 32;
                }
            }
            
            // the following 'if' statements are used for displaying the corresponding output
            if (strcmp(input_string,age_string) == 0)
            {
                cout << "Case 1, sorting by Age." << endl;
                break;
            }

            if (strcmp(input_string,id_string) == 0)
            {
                cout << "Case 2, sorting by ID." << endl;
                break;
            }

            if (strcmp(input_string,frn_string) == 0)
            {
                cout << "Case 3, sorting by First name." << endl;
                break;
            }

            if (strcmp(input_string,lsn_string) == 0)
            {
                cout << "Case 4, sorting by Last name." << endl;
                break;
            }

            if (strcmp(input_string,sex_string) == 0)
            {
                cout << "Case 5, sorting by Sex." << endl;
                break;
            }
            // in case the input has no corresponding output, the else statemen gets executed
            else{
                cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
                cin >> input_string;
                invalidinput == 1;
            }

        } while (invalidinput == 1);        
    
    // PART 1.5: Sorting patient records

    // the following variables are used for temporarily storing array elements
    int tempage;
    char tempid[ID_LENGTH + 1];
    char tempfirst[MAX_NAME_LENGTH];
    char templast [MAX_NAME_LENGTH];
    char tempsex;

    // the following section executes if input_string has "age" stored in it
    if (strcmp (input_string,age_string) == 0)
    {   
        // sorting of the array elements in ascending order starts from here.
        for (int i = 0; i <= 10; i++)
        {
            for (int n = i+1; n < 10; n++)
            {
                if (age[i] > age[n])
                {   
                    // here, the variable tempage stores age[i] (the greater value), loop assigns the value of age [n] (the lesser value) to age[i], and then assigns the value stored in tempage to age[n], effectively making age[i] < age[n]
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    // the following  code ensures that the other elements also shift along with the age elements.
                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;                    
                }

                // the below code is a tiebreaker, where 2 or more elements are sorted according to the first name, in case the age is equal. The tiebreaker code is only used in the cases of age and sex.
                else if (age[i] == age[n])
                {
                    if (strcmp (firstName[i],firstName[n]) > 0){
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;   
                    }                 
                }
                
            }
            
        }
        
    }

// the exact same logic is applied to the below codeblocks
        if (strcmp (input_string,id_string) == 0)
    {
        for (int i = 0; i <= 10; i++)
        {
            for (int n = i+1; n < 10; n++)
            {
                if (strcmp (id[i], id[n]) > 0)
                {
                    
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;                    
                }
                
            }
            
        }
        
    }

    if (strcmp (input_string,frn_string) == 0)
    {
        for (int i = 0; i <= 10; i++)
        {
            for (int n = i+1; n < 10; n++)
            {
                if (strcmp (firstName[i], firstName[n]) > 0)
                {
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    sex[0] = 'f';
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;                   
                }
                
            }
            
        }
        
    }

    if (strcmp (input_string,lsn_string) == 0)
    {
        for (int i = 0; i <= 10; i++)
        {
            for (int n = i+1; n < 10; n++)
            {
                if (strcmp (lastName[i], lastName[n]) > 0)
                {
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;                   
                }
                
            }
            
        }
        
    }

    if (strcmp (input_string,sex_string) == 0)
    {
        for (int i = 0; i <= 10; i++)
        {
            for (int n = i+1; n < 10; n++)
            {
                if (sex[i] > sex[n])
                {
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;                    
                }
                else if (sex[i] == sex[n])
                {
                    if (strcmp (firstName[i],firstName[n]) > 0){
                    tempage = age[i];
                    age[i] = age[n];
                    age[n] = tempage;

                    strcpy(tempid, id[i]);
                    strcpy(id[i], id[n]);
                    strcpy(id[n], tempid);

                    strcpy(tempfirst, firstName[i]);
                    strcpy(firstName[i], firstName[n]);
                    strcpy(firstName[n], tempfirst);
                    
                    strcpy(templast, lastName[i]);
                    strcpy(lastName[i], lastName[n]);
                    strcpy(lastName[n], templast);
                    
                    tempsex = sex[i];
                    sex[i] = sex[n];
                    sex[n] = tempsex;   
                    }                 
                }
                
            }
            
        }
        
    }

    // PART 2: Outputting patient records to terminal in tabular form
    
    // here the patient details are sorted according ot the user input in tabular form.
    cout << "=================================================================================================================================" << endl;
    cout << setw(12) << "Age:";
    for (int col = 0; col < 10; col++)
    {
        cout << setw(10) << age[col];
    }
    cout << endl;

    cout << setw(12) << "ID:";
    for (int col = 0; col < 10; col++)
    {
        cout << setw(10) << id[col];
    }
    cout << endl;

    cout << setw(12) << "First Name:";
    for (int col = 0; col < 10; col++)
    {
        cout << setw(10) << firstName[col];
    }
    cout << endl;

    cout << setw(12) << "Last Name:";
    for (int col = 0; col < 10; col++)
    {
        cout << setw(10) << lastName[col];
    }
    cout << endl;

    cout << setw(12) << "Sex:";
    for (int col = 0; col < 10; col++)
    {
        cout << setw(10) << sex[col];
    }
    cout << endl;
    cout << "=================================================================================================================================" << endl;

    cout << (id[5] - '0');

    return 0;
}