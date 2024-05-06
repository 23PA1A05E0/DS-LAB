#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node *
CreateNode (int data)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (struct node *));
  temp->data = data;
  return temp;
}

struct node *
insert (struct node *root, int data)
{
  if (root == NULL)
	return CreateNode (data);
  else
	{
	  if (data < root->data)
		{
		  root->left = insert (root->left, data);
		}
	  else if (data > root->data)
		{
		  root->right = insert (root->right, data);
		}

	  return root;
	}
}

void
Inorder (struct node *root)
{
  if (root->left != NULL)
	Inorder (root->left);
  printf ("%d ", root->data);
  if (root->right != NULL)
	Inorder (root->right);
}

void
Preorder (struct node *root)
{
  printf ("%d ", root->data);
  if (root->left != NULL)
	Preorder (root->left);

  if (root->right != NULL)
	Preorder (root->right);
}

void
Postorder (struct node *root)
{

  if (root->left != NULL)
	Preorder (root->left);

  if (root->right != NULL)
	Preorder (root->right);
  printf ("%d ", root->data);
}

int
search (struct node *root, int key)
{
  if (key == root->data)
	{
	  printf ("\nKey is found\n");
	  return 1;
	}
else{
	return 0;
} 
   if (key < root->data || key > root->data)
	{
	  if (key < root->data)
		{
		  search (root->left, key);

		}
	  if (key > root->data)
		{
		  search (root->right, key);
		}

	}

}

struct node *
findMin (struct node *root)
{
  if (root == NULL)
	{
	  return NULL;
	}
  else if (root->left != NULL)
	{
	  return findMin (root->left);
	}
  return root;
}

struct node *
delete (struct node *root, int x)
{
  if (root == NULL)
	{
	  return NULL;
	}
  else if (x < root->data)
	{
	  root->left = delete (root->left, x);
	}
  else if (x > root->data)
	{
	  root->right = delete (root->right, x);
	}
  else
	{
	  if (root->left == NULL && root->right == NULL)
		{
		  root = NULL;
		  free (root);
		  return NULL;
		}
	  else if (root->left == NULL || root->right == NULL)
		{

		  struct node *temp;
		  if (root->left == NULL)
			{
			  temp = root->right;
			}
		  else if (root->right)
			{
			  temp = root->left;
			}
		  free (root);
		  return temp;
		}
	  else
		{
		  struct node *temp = findMin (root->right);
		  root->data = temp->data;
		  root->right = delete (root->right, temp->data);
		}
	}

  return root;

}

int
main ()
{

  struct node *root = NULL;
  root = insert (root, 50);
  root = insert (root, 20);
  root = insert (root, 60);
  printf ("\nInorder manner:");
  Inorder (root);
  printf ("\nIn preorder manner:");
  Preorder (root);
  printf ("\nIn Postorder manner:");
  Postorder (root);


  struct node *temp = delete (root, 60);
  printf ("\nAfter Deletion\n");
  Inorder (temp);



}
