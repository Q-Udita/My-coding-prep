int maxHeight(int height[],int width[],int length[],int n)
{
    int i,j=1,k;
    vector<int> height1((3*n)+1);
    vector<int> width1((3*n)+1);
    vector<int> length1((3*n)+1);
    for(i=0;i<n;i++)
    {
        height1[j]=height[i];
        if(width[i] > length[i])
        {
            length1[j]=width[i];
            width1[j]=length[i];
        }
        else 
        {
            length1[j]=length[i];
            width1[j]=width[i];
        }
        j++;
        height1[j]=width[i];
        if(height[i] > length[i])
        {
            length1[j]=height[i];
            width1[j]=length[i];
        }
        else 
        {
            length1[j]=length[i];
            width1[j]=height[i];
        }
        j++;
        height1[j]=length[i];
        if(width[i] > height[i])
        {
            length1[j]=width[i];
            width1[j]=height[i];
        }
        else 
        {
            length1[j]=height[i];
            width1[j]=width[i];
        }
        j++;
    }
    
    vector<vector<int>> sort;
    sort.resize(2,vector<int>(1+(3*n)));
    for(i=1;i<=(3*n);i++)
    {
        sort[0][i]=i;
        sort[1][i]=length1[i]*width1[i];
    }
    for(i=1;i<(3*n);i++)
    {
        int min=i;
        for(j=i+1;j<(3*n)+1;j++)
        {
            if(sort[1][j] > sort[1][min])
            min=j;
        }
        int temp;
        if(min!=i)
        {
        temp=sort[1][min];
        sort[1][min]=sort[1][i];
        sort[1][i]=temp;
        temp=sort[0][min];
        sort[0][min]=sort[0][i];
        sort[0][i]=temp;
        }
    }
    
    vector<int> v((3*n)+1);
    for(i=1;i<=(3*n);i++)
        v[i]=height1[sort[0][i]];
    for(i=1;i <= (3*n);i++)
    {
        for(j=1;j<i;j++)
        {
            if((width1[sort[0][j]] > width1[sort[0][i]]) && (length1[sort[0][j]] > length1[sort[0][i]]) && ((v[j]+height1[sort[0][i]]) > v[i]))
            {
                v[i]=v[j]+height1[sort[0][i]];
                
            }
        }
    }
    k=INT_MIN;
    for(i=1;i<=(3*n);i++)
    {
        if(v[i]>k)
        k=v[i];
    }
    return k;
}
