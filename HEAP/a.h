#include <iostream>

template <typename t>
class Heap
{
private:
    t *data;
    int n;    // number of elements
    int size; // array capacity

public:
    Heap(int a = 10)
    {
        data = new t[a];
        n = 0;
        size = a;
    }

    void Reheapup(t *data, int f, int l)
    {
        int p = (l - 1) / 2;
        while (l > f)
        {
            if (data[p] < data[l])
            {
                std::swap(data[p], data[l]);
                l = p;
                p = (l - 1) / 2;
            }
            else
                break;
        }
    }

    void Reheap_down(t *data, int first, int last)
    {
        int lc = 2 * first + 1;
        int rc = 2 * first + 2;
        int maxc;

        while (lc <= last)
        {
            maxc = lc;

            if (rc <= last && data[rc] > data[lc])
                maxc = rc;

            if (data[first] < data[maxc])
            {
                std::swap(data[first], data[maxc]);
                first = maxc;
                lc = 2 * first + 1;
                rc = 2 * first + 2;
            }
            else
                break;
        }
    }

    void push_heap(t val)
    {
        if (n == size)
        {
            std::cout << "Heap overflow";
            return;
        }

        data[n] = val;
        Reheapup(data, 0, n);
        n++;
    }
    void pop_heap()
    {
        if (n == 0)
        {
            std::cout << "heap underflow";
        }
        --n;
        data[0] = data[n];
        Reheap_down(data, 0, n);
    }
    void display()
    {
        for (int i = 0; i < n; i++)
            std::cout << data[i] << "  ";
        std::cout << std::endl;
    }
    void heap_sort()
    {
        int l_index = n - 1;
        while (l_index > 0)
        {
            std::swap(data[0], data[l_index]);
            --l_index;
            Reheap_down(data, 0, l_index);
        }
    }
};

int main()
{
    Heap<int> h(10);
    h.push_heap(2);
    h.push_heap(10);
    h.push_heap(24);
    h.push_heap(18);
    h.push_heap(29);

    h.display();
    h.pop_heap();
    h.display();

    h.heap_sort();
    h.display();
}