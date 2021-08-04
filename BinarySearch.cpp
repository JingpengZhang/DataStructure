//
// Created by 41261 on 2021/8/4.
//
//在表Tbl中查找关键字为K的数据元素
int BinarySearch( List Tbl, ElementType K){
    int left,right,mid,NoFound = -1;
    left = 1;//初始左边界
    right = Tbl->Length;//初始右边界
    while ( left <= right ){
        mid = ( left + right )/2;//计算中间元素坐标
        if ( K < Tbl->Element[mid] ){
            right = mid - 1;//调整右边界
        } else if ( K > Tbl-> Element[mid] ){
            left = mid + 1;//调整左边界
        } else {
            return mid;//查找成功，返回数据元素的下标
        }
        return NoFound;//查找不成功，返回-1
    }
}
