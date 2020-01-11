#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<deque>
using namespace std;

class Puzzle
{
    public:
        int mat_parent_no;
        int mat_no;
        int mat[3][3];
};

int main()
{
    // static Goal Matrix
    int goal_matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    unsigned long int number = 1, travers = 0;
    bool flag = false;

    Puzzle puzzleObj;
    deque<Puzzle> puzzle_deque;

    cout << "Please Enter 3x3 Matrix: " << endl;
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            cout << "Matrix[" << row << "][" << col << "] = ";
            cin >> puzzleObj.mat[row][col];
        }
    }
    puzzleObj.mat_parent_no = 0;
    puzzleObj.mat_no = number++;

    puzzle_deque.push_back(puzzleObj);

    while(1)
    {
        Puzzle front_index;
        front_index = puzzle_deque[travers];
        travers++;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++ )
            {
                if(front_index.mat[i][j] != goal_matrix[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag == true)
                break;
        }
        if(flag == false)
        {
            while(1)
            {
                Puzzle s = front_index;
                cout << endl << "Matrix Parent No: " << s.mat_parent_no << endl;
                cout << "Matrix No: " << s.mat_no << endl;
                cout << "3x3 Matrix is:" << endl;
                for(int row = 0; row < 3; row++)
                {
                    for(int col = 0; col < 3; col++)
                        cout << s.mat[row][col] << " ";
                    cout << endl;
                }
                if(s.mat_parent_no == 0)
                {
                    cout << endl << "============ The END ============" << endl;
                    break;
                }

                front_index = puzzle_deque[s.mat_parent_no - 1];
            }
            break;

        } else
        {
            flag = false;
            int r, c;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(front_index.mat[i][j] == 0)
                    {
                        r = i;
                        c = j;
                        break;
                    }
                }
            }

            Puzzle ob1, ob2, ob3, ob4;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                    ob1.mat[i][j] = ob2.mat[i][j] = ob3.mat[i][j] = ob4.mat[i][j] = front_index.mat[i][j];
            }

            if(r == 0 && c == 0)
            {
                int temp = ob1.mat[0][1];
                ob1.mat[0][1] = ob1.mat[0][0];
                ob1.mat[0][0] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[1][0];
                ob2.mat[1][0] = ob2.mat[0][0];
                ob2.mat[0][0] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
            } else if (r == 0 && c == 1)
            {
                int temp = ob1.mat[0][2];
                ob1.mat[0][2] = ob1.mat[0][1];
                ob1.mat[0][1] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[1][1];
                ob2.mat[1][1] = ob2.mat[0][1];
                ob2.mat[0][1] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                int temp3 = ob3.mat[0][0];
                ob3.mat[0][0] = ob3.mat[0][1];
                ob3.mat[0][1] = temp3;

                ob3.mat_no = number++;
                ob3.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
                puzzle_deque.push_back(ob3);
            } else if (r == 0 && c == 2)
            {
                int temp = ob1.mat[1][2];
                ob1.mat[1][2] = ob1.mat[0][2];
                ob1.mat[0][2] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[0][1];
                ob2.mat[0][1] = ob2.mat[0][2];
                ob2.mat[0][2] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
            } else if (r == 1 && c == 0)
            {
                int temp = ob1.mat[2][0];
                ob1.mat[2][0] = ob1.mat[1][0];
                ob1.mat[1][0] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[1][1];
                ob2.mat[1][1] = ob2.mat[1][0];
                ob2.mat[1][0] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                int temp3 = ob3.mat[0][0];
                ob3.mat[0][0] = ob3.mat[1][0];
                ob3.mat[1][0] = temp3;

                ob3.mat_no = number++;
                ob3.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
                puzzle_deque.push_back(ob3);
            } else if (r == 1 && c == 1)
            {
                int temp = ob1.mat[1][2];
                ob1.mat[1][2] = ob1.mat[1][1];
                ob1.mat[1][1] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[2][1];
                ob2.mat[2][1] = ob2.mat[1][1];
                ob2.mat[1][1] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                int temp3 = ob3.mat[1][0];
                ob3.mat[1][0] = ob3.mat[1][1];
                ob3.mat[1][1] = temp3;

                ob3.mat_no = number++;
                ob3.mat_parent_no = front_index.mat_no;

                int temp4 = ob4.mat[0][1];
                ob4.mat[0][1] = ob4.mat[1][1];
                ob4.mat[1][1] = temp4;

                ob4.mat_no = number++;
                ob4.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
                puzzle_deque.push_back(ob3);
                puzzle_deque.push_back(ob4);
            } else if(r == 1 && c == 2)
            {
                int temp = ob1.mat[2][2];
                ob1.mat[2][2] = ob1.mat[1][2];
                ob1.mat[1][2] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[0][2];
                ob2.mat[0][2] = ob2.mat[1][2];
                ob2.mat[1][2] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                int temp3 = ob3.mat[1][1];
                ob3.mat[1][1] = ob3.mat[1][2];
                ob3.mat[1][2] = temp3;

                ob3.mat_no = number++;
                ob3.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
                puzzle_deque.push_back(ob3);
            } else if (r == 2 && c == 0)
            {
                int temp = ob1.mat[2][1];
                ob1.mat[2][1] = ob1.mat[2][0];
                ob1.mat[2][0] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[1][0];
                ob2.mat[1][0] = ob2.mat[2][0];
                ob2.mat[2][0] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
            } else if (r == 2 && c == 1)
            {
                int temp = ob1.mat[2][2];
                ob1.mat[2][2] = ob1.mat[2][1];
                ob1.mat[2][1] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[1][1];
                ob2.mat[1][1] = ob2.mat[2][1];
                ob2.mat[2][1] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                int temp3 = ob3.mat[2][0];
                ob3.mat[2][0] = ob3.mat[2][1];
                ob3.mat[2][1] = temp3;

                ob3.mat_no = number++;
                ob3.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
                puzzle_deque.push_back(ob3);
            } else if (r == 2 && c == 2)
            {
                int temp = ob1.mat[1][2];
                ob1.mat[1][2] = ob1.mat[2][2];
                ob1.mat[2][2] = temp;

                ob1.mat_no = number++;
                ob1.mat_parent_no = front_index.mat_no;

                int temp2 = ob2.mat[2][1];
                ob2.mat[2][1] = ob2.mat[2][2];
                ob2.mat[2][2] = temp2;

                ob2.mat_no = number++;
                ob2.mat_parent_no = front_index.mat_no;

                puzzle_deque.push_back(ob1);
                puzzle_deque.push_back(ob2);
            } else
            {
                cout << endl << "Ops! Something went wrong! " << endl;
                break;
            }
        }
    }
    getch();
}
