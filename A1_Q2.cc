/*
  By: Navraj Saini
  AI - spring 2018
  description: Problem 2 from A1
  The missionaries and cannibals problem is usually stated as follows. Three missionaries
  and three cannibals are on one side of a river, along with a boat that can hold one or two
  people. Find a way to get everyone to the other side without ever leaving a group of
  missionaries in one place outnumbered by the cannibals in that place.

  search: BFS (Queue)
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Check function to see if the number of cannibals <= Missionaries
//bool sCheck (queue <char>);
/*
  if the number of cannibals is <= missionaries
  return true else return false
 */
bool sCheck(queue <char> stk)
{
    int c = 0, m = 0;
    while (stk.size() != 0)
    {
        if (stk.front() == 'c')
        {
            stk.pop();
            c++;
        }
        else
        {
            stk.pop();
            m++;
        }
    }

    if (c <= m)
        return true;
    else
        return false;
}

int main ()
{
   //make the beginning and end queue and one for the boat
   queue <char> srt; queue <char> sEnd; queue <char> boat;

   //fill the queue with 3 C and 3 M
   srt.push('m'); srt.push('c'); srt.push('m');
   srt.push('m'); srt.push('c'); srt.push('c');

   boat.push(srt.front());
   srt.pop();
   boat.push(srt.front());
   srt.pop();

   while (srt.size()!= 0)
   {
      //if the start queue if still correct
      //push one on to the end queue
      if(sCheck(srt))
      {
	 sEnd.push(boat.front());
	 boat.pop();

	 if(!sCheck(sEnd))
	 {
	    boat.push(sEnd.front());
	    sEnd.pop();
	    srt.push(boat.front());
	    boat.pop();
	    boat.push(srt.front());
	    srt.pop();
	    sEnd.push(boat.front());
	    boat.pop();
	 }
      }
      //else
      //push back onto the start queue and
      //pop the next char onto the boat
      else
      {
          srt.push(boat.front());
          boat.pop();
          boat.push(srt.front());
          srt.pop();
          sEnd.push(boat.front());
          boat.pop();


          	 if(!sCheck(sEnd))
          	 {
          	     boat.push(sEnd.front());
          	     sEnd.pop();
          	     srt.push(boat.front());
          	     boat.pop();
          	     boat.push(srt.front());
          	     srt.pop();
          	     sEnd.push(boat.front());
          	     boat.pop();
          	 }
      }
      boat.push(srt.front());
      srt.pop();
   }
   sEnd.push(boat.front());
   boat.pop();
   sEnd.push(boat.front());
   boat.pop();

   //the output
    // in the order of what is dropped off on the other side

   int sz = sEnd.size();
   for (int i = 0; i < sz; i++)
   {
       cout << sEnd.front() << " ";
       sEnd.pop();
   }
   cout << endl;
}
