#include<stdio.h>
int main()    
{         
    int arr[100],arr_size,i;
    printf("Enter the size of an array\n");
    scanf("%d",&arr_size);   

    printf("Enter the elements in the array\n");  
    for(i=0;i<arr_size;i++) 
    {     
        scanf("%d",&arr[i]);     
    }  

    printf("The elements are:\n");  
    for(i=0;i<arr_size;i++) 
    {     
        printf("%d",arr[i]);     
    }    
         
     
    return 0;    
}      