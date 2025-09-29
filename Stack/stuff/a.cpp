#include<iostream>
#include<chrono>  //library to use the function that calculate execution time 
#include<ctime>   //library to generate random number 
#include<fstream>
int main(int arg, char** arey) //in arey takes name of .exe of this program and name of file at which result will be written  
{


    if (arg == 3)
    {
        srand(time(0));
        int i, j, temp, des;

        int size = atoi(arey[1]);

        int* random_array = new int[size];   //dynamic array that will store random values 

        int* ascending_order_array = new int[size]; //dynamic array to store sorted values 
        int* descending_order_array = new int[size];


        for (i = 0; i < size; ++i)    //assigning random values to array 
        {
            random_array[i] = rand() % 300000 + 1;
        }
        for (i = 0; i < size; ++i)    //assigning ascending order values to array 
        {
            ascending_order_array[i] = i + 1;
        }
        int assign = size;
        for (i = 0; i < size; ++i)    //assigning descending order values to array 
        {
            descending_order_array[i] = assign;
            --assign;
        }


        //calculating execution time for random array 

        auto start = std::chrono::high_resolution_clock::now();   //for calcualting time from start of sorting
        for (i = 0; i < size - 1; i++)
        {
            temp = random_array[i];
            for (j = i + 1; j < size - 2; j++)
            {
                if (temp > random_array[j])
                {
                    int sp = random_array[j];
                    random_array[j] = temp;
                    temp = sp;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();   //calculating time where sorting has been done
        auto t1_random_wrong_slection_sorting = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);   //calculating time taken in milli seconds 



        //calculating execution time for array sorted in ascending order

        start = std::chrono::high_resolution_clock::now();   //for calcualting time from start of sorting
        for (i = 0; i < size - 1; i++)
        {
            temp = ascending_order_array[i];
            for (j = i + 1; j < size - 2; j++)
            {
                if (temp > ascending_order_array[j])
                {
                    int sp = ascending_order_array[j];
                    ascending_order_array[j] = temp;
                    temp = sp;
                }
            }
        }
        end = std::chrono::high_resolution_clock::now();   //calculating time where sorting has been done
        auto t2_ascending_sorted_wrong_slection_sorting = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  //calculating time taken in milli seconds 

        //calculating execution time for array sorted in ascending order
        start = std::chrono::high_resolution_clock::now();   //for calcualting time from start of sorting
        for (i = 0; i < size - 1; i++)
        {
            temp = descending_order_array[i];
            for (j = i + 1; j < size - 2; j++)
            {
                if (temp > descending_order_array[j])
                {
                    int sp = descending_order_array[j];
                    descending_order_array[j] = temp;
                    temp = sp;
                }
            }
        }
        end = std::chrono::high_resolution_clock::now();  //calculating time where sorting has been done
        auto t3_descending_sorted_wrong_slection_sorting = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        //calculating time taken in milli seconds


        //deleting dynamically created array
        delete[] random_array;
        delete[] ascending_order_array;
        delete[] descending_order_array;

        //wrong slection sorting ends here

        ////////////////////////////////////////////////////
        ///////////////////////////////////////////////////
        ///////////////////////////////////////////////////

        //Right slection sorting starts here 


        random_array = new int[size];
        ascending_order_array = new int[size];
        descending_order_array = new int[size];

        for (i = 0; i < size; i++)  //assigning random values to array 
        {
            random_array[i] = rand() % 400000 + 1;
        }

        //assigning values to ascending order array
        for (i = 0; i < size; i++)
        {
            ascending_order_array[i] = i + 1;
        }

        //assigning values to descending order array 
        des = size;
        for (i = 0; i < size; i++)
        {
            descending_order_array[i] = des;
            --des;
        }

        start = std::chrono::high_resolution_clock::now();  //for calcualting time from start of sorting
        for (int i = 0; i < size - 1; i++)
        {
            temp = i;
            for (int j = i + 1; j < size - 2; j++)
            {
                if (random_array[temp] > random_array[j])
                {
                    temp = j;
                }
            }
            if (i != temp)
            {
                std::swap(random_array[i], random_array[temp]);
            }
        }

        end = std::chrono::high_resolution_clock::now(); //calculating time where sorting has been done 
        auto time_for_random_right_slection = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //calculating time taken in milli seconds 

        //calculating time for sorting ascending order array
        start = std::chrono::high_resolution_clock::now();
        for (i = 0; i < size - 1; i++)
        {
            temp = i;
            for (j = i + 1; j < size - 2; j++)
            {
                if (ascending_order_array[temp] > ascending_order_array[j])
                {
                    temp = j;
                }
            }
            if (temp != i)
            {
                std::swap(ascending_order_array[i], ascending_order_array[temp]);
            }
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_ascending_order_right_slection = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


        //calculating time for sorting descending order array 
        start = std::chrono::high_resolution_clock::now();
        for (i = 0; i < size - 1; i++)
        {
            temp = i;
            for (j = i + 1; j < size - 2; j++)
            {
                if (descending_order_array[temp] < descending_order_array[j])
                {
                    temp = j;
                }
            }
            if (i != temp)
            {
                std::swap(descending_order_array[i], descending_order_array[temp]);
            }
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_descend_order_right_slection = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);



        delete[] random_array;
        delete[] ascending_order_array;
        delete[] descending_order_array;

        //Right slection sorting ends here 
 //////////////////////////////////////////////
 //////////////////////////////////////////////
 //////////////////////////////////////////////
        //Bubble sorting starts here 


       
        random_array = new int[size];
        
        ascending_order_array = new int[size];

        descending_order_array = new int[size];

        for (int i = 0; i < size; i++)  //assigning random values to array 
        {
            random_array[i] = rand() % 500000 + 1;
        }

        //assigning values to ascending array
        for (i = 0; i < size; i++)
        {
            ascending_order_array[i] = i + 1;
        }

        //assigning values to descending array
        des = size;
        for (i = 0; i < size; i++)
        {
            descending_order_array[i] = des;
            --des;
        }

        start = std::chrono::high_resolution_clock::now(); //starting of time calculation

        for (int i = 0; i < size - 1; i++)   //bubble sortin
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (random_array[j] > random_array[j + 1])
                {
                    temp = random_array[j];
                    random_array[j] = random_array[j + 1];
                    random_array[j + 1] = temp;
                }
            }
        }
        end = std::chrono::high_resolution_clock::now();   //end of time calculation 
        auto time_for_random_array_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //coverting time in milli seconds


        //calculating time for ascending order bubble sorting 
        start = std::chrono::high_resolution_clock::now();
        for (i = 0; i < size - 1; i++)
        {

            for (j = 0; j < size - 1; j++)
            {
                if (ascending_order_array[j] > ascending_order_array[j + 1])
                {
                    temp = ascending_order_array[j];
                    ascending_order_array[j] = ascending_order_array[j + 1];
                    ascending_order_array[j + 1] = temp;
                }
            }
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_ascending_array_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        //calculating time for sorting descending order array
        start = std::chrono::high_resolution_clock::now();
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size - 1; j++)
            {
                if (descending_order_array[j] > descending_order_array[j + 1])
                {
                    temp = descending_order_array[j];
                    descending_order_array[j] = descending_order_array[j + 1];
                    descending_order_array[j + 1] = temp;
                }
            }
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_descending_array_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);



        delete[] random_array;
        delete[] ascending_order_array;
        delete[] descending_order_array;

        //end of bubble sorting 

        //////////////////////////////////////////
        /////////////////////////////////////////
        ////////////////////////////////////////

        //starting insertion sorting 

        
;
        random_array = new int[size];

        ascending_order_array = new int[size];

        descending_order_array = new int[size];

        //assigning random values to array 

        for (i = 0; i < size; i++)
        {
            random_array[i] = rand() % 500000 + 1;
        }

        //assigning values to ascending array
        for (i = 0; i < size; i++)
        {
            ascending_order_array[i] = i + 1;
        }

        //assigning values to descending array
        des = size;
        for (i = 0; i < size; i++)
        {
            descending_order_array[i] = des;
            --des;
        }


        start = std::chrono::high_resolution_clock::now();  //for calcualting time from start of sorting
        //performing insertion sorting in wrong way 
        for (i = 1; i < size; i++)
        {
            temp = random_array[i];
            j = i;
            while (j > 0 && temp < random_array[j - 1])
            {
                random_array[j] = random_array[j - 1];
                j--;
            }
            random_array[j] = temp;

        }
        end = std::chrono::high_resolution_clock::now();   //calculating time where sorting has been done
        auto time_for_random_array_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  //calculating time taken in milli seconds 


        //calculating time for ascending order array
        start = std::chrono::high_resolution_clock::now();
        for (i = 1; i < size ; i++)
        {
            j = i;
            temp = ascending_order_array[i];
            while (j > 0 && temp < ascending_order_array[j - 1])
            {
                ascending_order_array[j] = ascending_order_array[j - 1];
                --j;
            }
            ascending_order_array[j] = temp;
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_ascending_array_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        //calculating time for descending order array
        start = std::chrono::high_resolution_clock::now();
        for (i = 0; i < size; i++)
        {
            j = i;
            temp = descending_order_array[i];
            while (j > 0 && temp < descending_order_array[j - 1])
            {
                descending_order_array[j] = descending_order_array[j - 1];
                --j;
            }
            descending_order_array[j] = temp;
        }
        end = std::chrono::high_resolution_clock::now();
        auto time_for_descending_array_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        delete[] random_array;
        delete[] ascending_order_array;
        delete[] descending_order_array;


        ///////////////////////////////////
        // ///////////////////////////////
        // File handling part starts here 
        //writting time taken to sort the arrays in file whose name will be give in comman line argument 
        std::fstream file;

        file.open(arey[2], std::ios::app);
        if (file.is_open())
        {
            file << "Algorithm_Type,Size,Array_Type,Time_Taken,Time_scale \n";
            //writing results of wrong slection sorting 
            file << "Wrong slection sorting," << size << ",Random Array," << t1_random_wrong_slection_sorting.count() << "milli second \n";
            file << "Wrong slection sorting," << size << ",Ascending order," << t2_ascending_sorted_wrong_slection_sorting.count() << "milli second \n";
            file << "Wrong slection sorting," << size << ",Descending order," << t3_descending_sorted_wrong_slection_sorting.count() << "milli second\n";

            //writing result of right slection sorting

            file << "Right slection soring," << size << ",Random Array," << time_for_random_right_slection.count() << "milli second\n";
            file << "Right slection soring," << size << ",Ascending Array," << time_for_ascending_order_right_slection.count() << "milli second\n";
            file << "Right slection soring," << size << ",Descending Array," << time_for_descend_order_right_slection.count() << "milli second\n";

            //writing result of bubble sorting
            file << "Bubble Sorting," << size << ",Random Array," << time_for_random_array_bubble.count() << "milli second\n";
            file << "Bubble Sorting," << size << ",Ascending Array," << time_for_ascending_array_bubble.count() << "milli second\n";
            file << "Bubble Sorting," << size << ",Descending Array," << time_for_descending_array_bubble.count() << "milli second\n";

            //writting result of insetion sorting

            file << "Insertion Sorting," << size << ",Random Array," << time_for_random_array_insertion.count() << "milli seconds \n";
            file << "Insertion Sorting," << size << ",Ascending Array," << time_for_ascending_array_insertion.count() << "milli seconds \n";
            file << "Insertion Sorting," << size << ",Descending Array," << time_for_descending_array_insertion.count() << "milli seconds \n";


            std::cout << "Result enterd";
        }
        else
        {
            std::cout << "file not opened";
        }

    }
    else
    {
        std::cout << "Usage =  size_of_array  Name_of_csv_file  ";
    }
    return 0;
}