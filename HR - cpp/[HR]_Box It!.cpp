
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


class Box {
    private:
        int l, b, h;
    
    public:
    Box()
    {
        l =0 ;
        b =0 ;
        h =0 ;
    }

    Box(int m_l, int m_b, int m_h)
    {
        l = m_l;
        b = m_b;
        h = m_h;
    }

    Box(Box& m_box)
    {
        l = m_box.getLength();
        b = m_box.getBreadth();
        h = m_box.getHeight();
    }

    unsigned long long CalculateVolume()
    {
        unsigned long long x =  (unsigned long long)l*(unsigned long long)b*(unsigned long long)h;
        return x;
    } 

    int getLength()
    {
        return l;
    }

    int getBreadth()
    {
        return b;
    }

    int getHeight()
    {
        return h;
    }

    bool operator<(Box& m_b)
    {
        if (h < m_b.getHeight() && b == m_b.getBreadth() && l == m_b.getLength())
            return true;
        else if  (b < m_b.getBreadth() && l == m_b.getLength())
            return true;
        else if(l < m_b.getLength())
            return true;
        
        return false;
    }

    
};

ostream& operator<<(ostream& out, Box& B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out ;
}
