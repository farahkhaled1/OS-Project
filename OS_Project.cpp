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

    // we display the process number, process size , block number and block size
    cout << "\nProcess No.\tProcess Size\tBlock no.\tBlock Size\n";
    for (int i = 0; i < number_of_processes; i++)
    {
        cout << " " << i + 1 << "\t\t\t\t"
            << process_size[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << "\t\t" << allocation[i] + 1;
            cout << "\t\t\t" << block_size[i];
        }
        else {
            cout << "\t" << "Not Allocated";
        }
        cout << endl;
    }
}

// Driver code
void bestfit()

{
    cout << "l";
}
void worstfit()
{
    cout << "k";
}


int main()
{
    int number_of_blocks, number_of_processes;

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

    cout << "Enter 1 to apply first fit algorithm, 2 for best fit algorithm, 3 for worst fit algorithm. ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        firstFit(block, number_of_blocks, process, number_of_processes);
        break;
    case '2':
        bestfit();
        break;
    case '3':
        worstfit();
        break;
    default:
        cout << "Invalid value " << endl;

    }

}