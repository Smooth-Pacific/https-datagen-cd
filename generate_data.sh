#!/bin/bash

python3 gen_csv.py

if [ -f ./build/src/users ];
then
    ./build/src/users
else
    echo "./build/src/users not found"
    exit
fi

if [ -f ./build/src/credit_card ];
then
    ./build/src/credit_card
else
    echo "./build/src/credit_card not found"
    exit
fi

if [ -f ./build/src/credit_card_user ];
then
    ./build/src/credit_card_user
else
    echo "./build/src/credit_card_user not found"
    exit
fi

if [ -f ./build/src/merchants ];
then
    ./build/src/merchants
else
    echo "./build/src/merchants not found"
    exit
fi

if [ -f ./build/src/states ];
then
    ./build/src/states
else
    echo "./build/src/states not found"
    exit
fi