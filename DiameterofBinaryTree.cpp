int height = 0;


height is used to set parent height;

int diameter(node * root,int * height)
{
    if(root==NULL)
    {
        * height = 0;
        return 0;
    }
    
    
    int lh=0;
    int rh =0;
    int ld =0;
    int rd =0;
    
    ld  =  diameter (root->left,ld);
    rd  =diameter (root->right ,rd);
    
    int height  =1+max(lh,rh);
    
    return max(ldiamter,rdiamter,1+lh+rh);
    
    
}
