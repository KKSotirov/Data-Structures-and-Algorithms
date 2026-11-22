#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int abs(int val)
{
    if (val < 0)
        val *= (-1);
    return val;
}

std::vector<int> asteroidCollision(std::vector<int> &asteroids)
{
    std::reverse(asteroids.begin(), asteroids.end());

    std::stack<int> chuckNorris;

    while (!asteroids.empty())
    {
        bool alive = true;

        while (!chuckNorris.empty() &&
               chuckNorris.top() > 0 &&
               asteroids.back() < 0 &&
               alive)
        {
            // collision incoming!  Now to calculate the outcome:
            if (abs(asteroids.back()) > chuckNorris.top())
                chuckNorris.pop();

            else
            {
                if (abs(asteroids.back()) == chuckNorris.top())
                    chuckNorris.pop();
                alive = false;
            }
        }

        if (alive)
            chuckNorris.push(asteroids.back());

        asteroids.pop_back();
    }

    // The asteroids left in chuckNorris are those who've survived!
    while (!chuckNorris.empty())
    {
        asteroids.push_back(chuckNorris.top());
        chuckNorris.pop();
    }

    std::reverse(asteroids.begin(), asteroids.end());
    return asteroids;
}

int main()
{
    std::vector<int> asteroids{10, 2, -5};
    asteroidCollision(asteroids);
    std::cout << "Here are the remaining asteroids: \n";
    std::reverse(asteroids.begin(), asteroids.end());

    while (!asteroids.empty())
    {
        std::cout << asteroids.back() << " ";
        asteroids.pop_back();
    }

    return 0;
}