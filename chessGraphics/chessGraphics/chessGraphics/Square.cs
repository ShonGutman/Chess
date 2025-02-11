﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace chessGraphics
{
    public class Square
    {
        int _colIndex;
        int _rowIndex;
        char _pieceType;
        
        public Square(int row, int col)
        {
            _rowIndex = row;
            _colIndex = col;
            _pieceType = '#';
        }

        public Square(int row, int col, char piece)
        {
            _rowIndex = row;
            _colIndex = col;
            _pieceType = piece;
        }

        public int Row
        {
            get { return _rowIndex; }
        }

        public int Col
        {
            get { return _colIndex; }
        }

        public char Type
        {
            get { return _pieceType; }
            set { _pieceType = value; }
        }

        public override string ToString()
        {
            return Convert.ToChar('a' + _colIndex).ToString() + (8 - _rowIndex).ToString();
        }
    }
}
