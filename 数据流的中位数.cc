#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> left;
    priority_queue<int,vector<int>> right;
    MedianFinder() {
        
    }
    /*
        原则
        left中的元素都小于right中的元素
        left的大小=right的大小or比right大1
    */
    /*
        left.size() == right.size()
        num较大，放入right，此时right.size() > left.size(),将right堆顶push到left，right弹出堆顶
        num较小，放入left，符合原则
        可以合并为right放入num,left放入right堆顶(后半区最小值),right弹出堆顶

        left.size() > right.size()
        num较大，放入right，符合原则
        num较小，放入left，此时left.size() > right.size() + 1,将left堆顶放入right，left弹出堆顶
        可以合并为left放入num,right放入left堆顶(前半区最大值),left弹出堆顶
    */
    void addNum(int num) {
        if (left.size() == right.size()) {
            right.push(num);
            int x = right.top();
            right.pop();
            left.push(x);
        }else if(left.size() == right.size() + 1) {
            left.push(num);
            int x = left.top();
            left.pop();
            right.push(x);
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};

/**
    * Your MedianFinder object will be instantiated and called as such:
    * MedianFinder* obj = new MedianFinder();
    * obj->addNum(num);
    * double param_2 = obj->findMedian();
    */

int main() {

    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    cout << medianFinder->findMedian() << '\n';
    medianFinder->addNum(3);
    cout << medianFinder->findMedian();

    return 0;
}