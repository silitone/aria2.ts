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
    vt = []
    f = []

    buffer = []

    with open(args.filename, 'r') as input:
        for line in input:
            data = line.strip()
            if data[0] == '#':
                continue

            parts = data.split()

            if parts[0] == 'v':
                v.append([float(x) for x in parts[1:]])
            elif parts[0] == '