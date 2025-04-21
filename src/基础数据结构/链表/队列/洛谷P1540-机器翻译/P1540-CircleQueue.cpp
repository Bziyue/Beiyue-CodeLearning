#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int Hash[N] = {0};
class CircleQueue
{
public:
    int size;
    int head , rear;

    int* data;
    CircleQueue(int capacity) //构造函数
    {
        size = capacity;
        data = new int[size];
        head = rear = 0;
    }
    ~CircleQueue()
    {
        delete[] data;
    }

    bool is_empty()
    {
        if(head == rear) return true;
        else return false;
    }
    bool is_full()
    {
        if((rear + 1) % size == head) return true;
        else return false;
    }
    bool push(int num)
    {
        if(is_full()) return false;
        else
        {
            data[rear] = num; 
            rear = (rear + 1) % size; //rear指向最后一个元素的后一个位置
        }

        return true;
    }
    int front()
    {
        if(is_empty()) return -1;
        else return data[head];
    }
    bool pop()
    {
        if(is_empty()) return false;
        else
        {
            head = (head + 1) % size; //形成循环
        }

        return true;
    }

    int sizeofCircleQue()
    {
        return (rear - head + size) % size; //放置rear跑到head前面为负
    }

};

int main()
{
    int n , m; cin>>m>>n;
    CircleQueue mem(m+1); //循环队列会有一个元素未使用用于判断是否为满
    int cnt = 0;
    while(n--)
    {
        int word; cin >> word;
        if(Hash[word]) continue; //如果已经在内存，不进行操作
        else
        {
            //检查是否已满
            // if(mem.sizeofCircleQue() == m)
            if(mem.is_full())
            {
                Hash[mem.front()] = 0; //出队
                mem.pop();
            }

            //进行查询并入队
            mem.push(word);
            cnt++;
            Hash[word] = 1;
        }

    }

    cout<<cnt<<endl;
    return 0;
}