#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse as arg
import struct as st
import os.path as ph

def parse():
    parser = arg.ArgumentParser( description='Convert OBJ model to NMD.')
    parser.add_argument('filename', type=str, help='Input OBJ model filename')

    args = parser.parse_args()
    return args

def entry():
    args = parse()

    v = []
    vn = []
    v