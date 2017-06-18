#!/bin/sh

./parser $1
jasmin gene.j
java demo
