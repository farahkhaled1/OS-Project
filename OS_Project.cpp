#include <iostream>
#include <cstring>

using namespace std;

void firstFit(int* block_size, int number_of_blocks, int* process_size, int number_of_processes)
{
    // we created an array to store the assigned blocks to their suitable processes 
    int* allocation = new int[number_of_processes];


    // The for loop is used to prevent assigning any block to any process by inistializing every element in the array with -1    
    for (int i = 0; i < number_of_processes; i++)
    {
        allocation[i] = -1;
    }

    // pick each process and find the first suitable block according to its size ad assign to it
    for (int i = 0; i < number_of_processes; i++)
    {
        for (int j = 0; j < number_of_blocks; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                // allocate block j to p[i] process
                allocation[i] = j;

                // Reduce available memory in this block.
                block_size[j] -= process_size[i];

                break;
            }
        }
    }

    // we display the process number, process size , block number
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < number_of_processes; i++)
    {
        cout << " " << i + 1 << "\t\t\t"
            << process_size[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << "\t\t" << allocation[i] + 1;
        }
        else {
            cout << "\t" << "Not Allocated";
        }
        cout << endl;
    }
}

//WorstFit:
void worstFit(int* block_size, int number_of_blocks, int* process_size, int number_of_processes)
{
    //First: Create an array to asssign each block to it's suitable process.
    int* allocation = new int[number_of_processes];
    //Second: Inistialize each element in the array to -1.
    for (int i = 0; i < number_of_blocks; i++)
    {
        allocation[i] = -1;
    }
    //Third: Create an array to assign each process to the least suitable block according to it's size.
    for (int i=0; i<number_of_processes; i++)
    {
        int index = -1;
        //Evaluate the array of blocks to find the least suitable block for the current process.
        for (int j=0; j<number_of_blocks; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                if (index == -1)
                    index = j;
                   
                else if (block_size[index] < block_size[j])
                    index = j;
            }
        }
        if (index != -1)
        {
            //Allocate index j to the process value.
            allocation[i] = index;
            //Reduce available memory in this block.
            block_size[index] -= process_size[i];
        }
    }
        // we display the process number, process size , block number and block size
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < number_of_processes; i++)
    {
        cout << " " << i + 1 << "\t\t\t"
            << process_size[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << "\t\t" << allocation[i] + 1;
            
        }
        else {
            cout << "\t" << "Not Allocated";
        }
        cout << endl;
    }
}


//BestFit:
void bestFit(int* block_size, int number_of_blocks, int* process_size, int number_of_processes)
{
    //First: Create an array to asssign each block to it's suitable process.
    int* allocation = new int[number_of_processes];
    //Second: Inistialize each element in the array to -1.
    for (int i = 0; i < number_of_blocks; i++)
    {
        allocation[i] = -1;
    }
    //Third: Create an array to assign each process to the most suitable block according to it's size.
    for (int i=0; i<number_of_processes; i++)
    {
        int index = -1;
        //Evaluate the array of blocks to find the most suitable block for the current process.
        for (int j=0; j<number_of_blocks; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                if (index == -1)
                    index = j;
                else if (block_size[index] > block_size[j])
                    index = j;
            }
        }
        if (index != -1)
        {
            //Allocate index j to the process value.
            allocation[i] = index;
            //Reduce available memory in this block.
            block_size[index] -= process_size[i];
        }
    }
      // we display the process number, process size , block number and block size
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < number_of_processes; i++)
    {
        cout << " " << i + 1 << "\t\t\t"
            << process_size[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << "\t\t" << allocation[i] + 1;
            
        }
        else {
            cout << "\t" << "Not Allocated";
        }
        cout << endl;
    }

}

//DriverCode:
int main()
{
    int number_of_blocks, number_of_processes,y;

    do{
    cout << "Enter total number of blocks: ";
    cin >> number_of_blocks;
    int* block = new int[number_of_blocks];
    
    for (int i = 0; i < number_of_blocks; i++) {
        cout <<endl;
        cout << "\nEnter size of block " << i+1 << " : ";
        cin >> block[i];
    }
    cout << "\nEnter total number of processes: ";
    cin >> number_of_processes;
    int* process = new int[number_of_processes];
    for (int i = 0; i < number_of_processes; i++)
    {
        cout <<endl;
        cout << "Enter size of process " << i+1 << " : ";
        cin >> process[i];
    }

    char choice;

    cout << "\nEnter 1 to apply first fit algorithm, 2 for best fit algorithm, 3 for worst fit algorithm. ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        firstFit(block, number_of_blocks, process, number_of_processes);
        break;
    case '2':
        bestFit(block, number_of_blocks, process, number_of_processes);
        break;
    case '3':
        worstFit(block, number_of_blocks, process, number_of_processes);
        break;
    default:
        cout << "Invalid value " << endl;

    }
    //User chooses if they're willing to continue using the program.
    cout << "\nEnter 1 if you wish to continue, enter 0 to stop: ";
    cin >>y;
    cout << "\n";
   }while(y==1); 
   cout << "\nThanks for using our program!";
}