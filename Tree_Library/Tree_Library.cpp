#include <iostream>
#include <vector>
#include <list>

/// \brief Standard tree node class
class Standard_Tree_Node
{
public:
    int data;
    std::vector<Standard_Tree_Node*> children;
    Standard_Tree_Node* Parent;
};

class Standard_Tree
{
public:

    int Depth = 0;
    int Max_Depth = 0;
    Standard_Tree_Node* root;
    Standard_Tree_Node* temp_node;
    std::vector<Standard_Tree_Node*> Node_List;

    
    /// \brief Create new standard tree node
    /// \param data Data of the node
       Standard_Tree_Node* new_standard_tree_node(int data, Standard_Tree_Node* Parent)
        {
            Standard_Tree_Node* node = new Standard_Tree_Node();
            node->data = data;
            node->Parent = Parent;
            Node_List.push_back(node);
            if (Parent != NULL)
                Parent->children.push_back(node);
            return node;
            
    }
    /// \brief Find random node
    Standard_Tree_Node* find_random_node()
    {
           return Node_List[rand() % Node_List.size()-1];;
    }
    
    Standard_Tree_Node* create_node_randomly(int data)
    {
           return new_standard_tree_node(data, find_random_node());
    }

   

    /// \brief Get sum of standard tree
    /// \param root Root of the tree
   static int get_sum_of_standard_tree(Standard_Tree_Node* root)
    {
        if(root == NULL)
            return 0;

        int sum = root->data;
        for(int i = 0; i < root->children.size(); i++)
        {
            sum += get_sum_of_standard_tree(root->children.front());
            root->children.push_back(root->children.front());
            root->children.erase(root->children.begin());
        }
        return sum;
    }


    /// \brief Print standard tree
    /// \param root node used as root in print
    static void print_standard_tree(Standard_Tree_Node* root)
    {
        if(root == NULL)
            return;

        std::cout<<root->data<<std::endl;
        for(int i = 0; i < root->children.size(); i++)
        {
            print_standard_tree(root->children.front());
            root->children.push_back(root->children.front());
            root->children.erase(root->children.begin());
        }
    }

    /// \brief Find parent of node
    /// \param node Node to find parent of
    static void find_parent(Standard_Tree_Node* node)
   {
       if(node->Parent == NULL)
       {
           std::cout<<"Node is root"<<std::endl;
           return;
       }
       std::cout<<node->Parent->data<<std::endl;
   }

    /// \brief Finding all direct children of node
    /// \param node Node to find children of
    static int find_children(Standard_Tree_Node* node)
   {
       if (node->children.size() == 0)
       {
           std::cout<<"Node is leaf"<<std::endl;
           return 0;
       }
       for (Standard_Tree_Node* i: node->children)
       {
           std::cout<<"Printing data from all children"<<std::endl;
           std::cout<<i->data<<std::endl;
       }
       return 1;
   }

    /// \brief Check if node is leaf
    /// \param node Node to check
    static bool is_Leaf(Standard_Tree_Node* node)
   {
       if(find_children(node) == 0)
       {
           return true;
       }
       std::cout << "Node is not leaf" << std::endl;
       std::cout << "All children printed above" << std::endl;
       return false;
   }

    /// \brief Check if node is root
    /// \param node Node to check
    static bool is_Root(Standard_Tree_Node* node)
   {
       if(node->Parent == NULL)
       {
           return true;
       }
       return false;
   }

    /// \brief Find root of tree
    /// \param node Node to start from
   static Standard_Tree_Node* find_root(Standard_Tree_Node* node)
    {
        if(node->Parent == NULL)
        {
            return node;
        }
        find_root(node->Parent);
        return node;
    }

    /// \brief Find depth of node
    /// \param node Node to find depth of
    static void find_Depth_of_Node(Standard_Tree_Node* node)
   {
       int Depth = 0;
       while(node->Parent != NULL)
       {
           Depth++;
           node = node->Parent;
       }
       std::cout << "Depth of node is: " << Depth << std::endl;
   }

    /// \brief Finding max depth of tree
    /// \param node Node to start from
    void find_Depth_of_Tree(Standard_Tree_Node* node)
   {
       finding_Depth_of_Tree(node);
       std::cout << "Depth of tree is: " << Max_Depth << std::endl;
   }

    /// \bried Find total size of tree
    void find_size() 
    {
       std::cout << "Size of tree is: " << Node_List.size() << std::endl;
    }
private:
    void finding_Depth_of_Tree(Standard_Tree_Node* node)
   {
       if(node->children.empty())
       {
           if(Depth > Max_Depth)
           {
               Max_Depth = Depth;
           }
       }
       else
       {
           Depth++;
           for(auto child: node->children)
           {
               temp_node = child;
               finding_Depth_of_Tree(temp_node);
           }
           Depth--;
       }
       
   }
};

int main(int argc, char* argv[])
{
     Standard_Tree Tree;
     Tree.root = Tree.new_standard_tree_node(1, NULL);
    
     Tree.new_standard_tree_node(2, Tree.root);
     Tree.new_standard_tree_node(3, Tree.root);
    
     Tree.new_standard_tree_node(4, Tree.root->children[0]);
     Tree.new_standard_tree_node(5, Tree.root->children[0]);
     Tree.new_standard_tree_node(6, Tree.root->children[0]);
     Tree.new_standard_tree_node(7, Tree.root->children[1]);
     Tree.new_standard_tree_node(8, Tree.root->children[1]);
    
     Tree.new_standard_tree_node(9, Tree.root->children[0]->children[0]);
     Tree.new_standard_tree_node(10, Tree.root->children[0]->children[0]);
     Tree.new_standard_tree_node(11, Tree.root->children[0]->children[1]);
     Tree.new_standard_tree_node(12, Tree.root->children[1]->children[0]);
     Tree.new_standard_tree_node(13, Tree.root->children[1]->children[1]);
    
     Tree.new_standard_tree_node(14, Tree.root->children[1]->children[0]->children[0]);
     Tree.new_standard_tree_node(15, Tree.root->children[1]->children[1]->children[0]);
    
     Tree.new_standard_tree_node(16, Tree.root->children[1]->children[1]->children[0]->children[0]);
    
    Tree.new_standard_tree_node(17, Tree.find_random_node());
    
     Tree.find_Depth_of_Tree(Tree.root);
     Tree.find_size();
    return 0;
}
