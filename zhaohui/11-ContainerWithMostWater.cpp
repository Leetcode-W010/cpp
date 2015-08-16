/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty() || height.size()==1)
			return 0;
		int num = height.size();
		int left = 0,right = num - 1,tempA;
		int maxA = 0;
		for(left =0;left<num-1;left++){
			right = left;
			while(right<num -1){
				right = maxInd(height,right+1,num);
				tempA = (right - left)*min(height[left],height[right]);
				if(maxA < tempA){
					maxA = tempA;
				}				
			}
		}
		return maxA;
    }
	
	int maxArea1(vector<int>& height) {
        if(height.empty() || height.size()==1)
			return 0;
		int num = height.size();
		vector<int> left,right;
		int leftLen=0,rightLen=0;
		int first = 0,second = 1,temp;
		for(int i=2;i<num;i++){
			if(height[i]>min(height[first],height[second])){
				first = second;
				second = i;
			}
		}
		int maxA = (second - first)*min(height[first],height[second]);
		left.push_back(first);
		right.push_back(second);
		leftLen++;
		rightLen++;
		int tempL,tempR,tempA;
		while(left[leftLen-1]>0 || right[rightLen-1]<num-1){
			if(left[leftLen-1]>0){
				tempL = maxInd(height,0,left[leftLen-1]);
				leftLen ++ ;
				left.push_back(tempL);
				int i=rightLen-1;
				for(;height[right[i]]<height[tempL];i--){
					tempA = height[right[i]] * (right[i] - tempL);
					if(maxA < tempA)
						maxA = tempA;
					
				}
				tempA = height[tempL] * (right[i] - tempL);
				if(maxA < tempA)
					maxA  = tempA;				
			}
			
			if(right[rightLen-1]<num-1){
				tempR = maxInd(height,right[rightLen-1]+1,num);
				rightLen ++;
				right.push_back(tempR);
				int i = leftLen -1;
				for(; height[left[i]]<height[tempR];i--){
					tempA = height[left[i]] * (tempR - left[i]);
					if(maxA < tempA)
						maxA = tempA;
				}
				tempA = height[tempR] * (tempR - left[i]);
				if(maxA < tempA)
					maxA = tempA;				
			}
		}		
		return maxA;
    }

	int maxInd(vector<int>& height,int start,int end){
		int maxPos = start;
		int maxH = height[start];
		if(end - start == 1)
			return maxPos;
		for(int i=start;i<end;i++){
			if(maxH < height[i]){
				maxPos = i;
				maxH = height[i];
			}		
		}
		return maxPos;
	}
};

int main(){
	int hArray[]={2,3,10,5,7,8,9};
	vector<int> test;
	vector<int> height(hArray,hArray+7);
	Solution solution;
	cout<<solution.maxArea1(height);
	return 0;
}