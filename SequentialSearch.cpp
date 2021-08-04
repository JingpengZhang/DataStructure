//
// Created by 41261 on 2021/8/4.
//
//在Element[1]~Element[n]中查找关键字为K的数据元素，无哨兵
int SequentialSearch( List Tbl, ElementType K ){
    int i;
    for ( i = Tbl->Length; i > 0 && Tbl->Element[i] != K; i-- );
    return i;//查找成功返回所在单元下标；不成功返回0
}
