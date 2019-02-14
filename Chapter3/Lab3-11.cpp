/* A little lottery */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool is_extracted(int extractedBall, int all_balls[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(all_balls[i] == extractedBall)
            return false;
    }

    return true;
}

void drawBalls(int max, int ballsNo)
{
    int *extractedBalls = new int[ballsNo];
    int extractedBall;
    int k = 0;
    // initialize to 0 , clean the garbage values
    for(int i = 0; i < ballsNo; i++)
    {
        extractedBalls[i] = 0;
    }

    while(ballsNo > 0)
    {
        extractedBall = rand() % max + 1;
        if(is_extracted(extractedBall, extractedBalls, ballsNo))
        {
            extractedBalls[k] = extractedBall;
            cout << extractedBall << " " << endl;
        }
        else
        {
            continue;
        }
        k++;
        ballsNo--;
    }

    delete [] extractedBalls;
}

int main(void)
{
    int maxball;
    int ballsno;


    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;
    srand(time(NULL));
    
    drawBalls(maxball, ballsno);

    return 0;
}
