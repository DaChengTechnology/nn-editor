﻿#pragma once
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>

template <class T1, class T2>
struct OrderMap : public std::vector<std::pair<T1, T2>>
{
    T2& operator[](T1 t)
    {
        for (auto& k : *this)
        {
            if (k.first == t)
            {
                return k.second;
            }
        }
        this->emplace_back();
        this->back().first = t;
        return this->back().second;
    }
    const T2& operator[](T1 t) const
    {
        for (auto& k : *this)
        {
            if (k.first == t)
            {
                return k.value;
            }
        }
    }
    size_t count(T1 t) const
    {
        for (auto& k : *this)
        {
            if (k.first == t)
            {
                return 1;
            }
        }
        return 0;
    }
    void erase(T1 t)
    {
        for (auto it = this->begin(); it != this->end(); it++)
        {
            if (it->first == t)
            {
                erase(it);
                return;
            }
        }
    }
};

struct Node
{
    enum
    {
        MAX_PIN = 256,    //一个node最多的pin数
        HALF_MAX_PIN = MAX_PIN / 2,
    };

    std::string title;
    std::string type;
    std::string text;
    OrderMap<std::string, std::string> values;

    std::vector<Node*> prevs, nexts;    //需注意下面的prev_pin和next_pin是画图的点数，准许大于等于size

    //use to draw nodes
    int id, text_id;
    int prev_pin = 0, next_pin = 0;
    int position_x = -1, position_y = -1;
    int erased = 0;

    // 辅助值
    std::vector<std::string> in, out;
    int turn = 0;
};


/*
    接口应实现从文件到std::deque<Node>的转换，包含title，type，可编辑值等
    text可以加入编辑列表中没有的值
    Node的初始坐标可以自行计算，或者也可以调用Loader中自带的一个算法
*/
