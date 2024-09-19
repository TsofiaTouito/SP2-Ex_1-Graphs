//tsofiatouito2@gmail.com
//id-324953900

#include "Graph.hpp"

using namespace std;
using namespace ariel;

using std::string;
using std::vector;



void Graph::loadGraph(const vector<vector<int>> graph){
if(graph.empty()|| graph.size()!= graph[0].size()){

    throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
}

    this->adjMat = graph; 
    this->vertices = graph.size();

    //check if the graph is symmetric / weighted
    for(size_t i = 0; i < this->vertices ; i++){
        for(size_t j = 0; j < this->vertices ; j++){
            if(adjMat[i][j]!=adjMat[j][i]){
                this->is_symmetric = false; // the graph is directed
            }
            if(adjMat[i][j]!=0 && adjMat[i][j]!=1){
                this->is_weighted = true; // the graph is weighted
            }
            if(adjMat[i][j] < 0){
                this->neg_values = true;
            }
        }
    }
    this->is_loaded = true;
}



void Graph::printGraph(){

if(!this->is_loaded){
        throw invalid_argument("The graph is not loaded");
    }

int edges = 0;

for(size_t i = 0; i < this->vertices ; i++){
    for(size_t j = 0; j < this->vertices ; j++){
        if(adjMat[i][j]!= 0){
            edges++;
        }
    }
}

cout<< "Graph with " << this->vertices << " vertices and " << edges << " edges."<<endl;
}



vector<vector<int>> Graph::getGraph() const{
    return this->adjMat;
}


bool Graph::isSymmetric() const {
    return this->is_symmetric;
 }


bool Graph::isWeighted()const {
    return this->is_weighted;
}


bool Graph::isLoaded() const{ 
    return this->is_loaded;
}

bool Graph::hasNegVal() const{
    return this->neg_values;
}



//operators implementation 

Graph& Graph::operator+(){  // Operator + unary
    return *this;
}
Graph Graph::operator+(const Graph& other){    // Graph+other

    if(!sizeCheck(*this, other)){
        throw invalid_argument("The graphs are not of the same dimensions.");  //n*n
    }

Graph sumGraph;
const vector<vector<int>> &otherG = other.getGraph();
size_t size = otherG.size();
vector<vector<int>> sum(size, vector<int>(size, 0));

for(size_t i = 0; i < size ; i++){
    for(size_t j = 0 ; j < size ; j++){
        sum[i][j] = this->adjMat[i][j] + otherG[i][j] ;
    }
}

sumGraph.loadGraph(sum);
return sumGraph;
}




Graph& Graph::operator+=(const Graph& other){   // Graph+=other

    if(!sizeCheck(*this, other)){
        throw invalid_argument("The graphs are not of the same dimensions.");  //n*n
    }

const vector<vector<int>> &otherG = other.getGraph();
size_t size = otherG.size();

for(size_t i = 0; i < size ; i++){
    for(size_t j = 0 ; j < size ; j++){
        this->adjMat[i][j] += otherG[i][j];
    }
}
return *this;   
}



Graph& Graph::operator-(){   // Operator - unary
    return *this;
}
 


Graph Graph::operator-(const Graph& other){   // Graph-other

    if(!sizeCheck(*this, other)){
        throw invalid_argument("The graphs are not of the same dimensions.");
    }


const vector<vector<int>>& otherG = other.getGraph();
size_t size = otherG.size();

Graph subGraph;
vector<vector<int>> sub(size, vector<int>( size, 0));

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
        sub[i][j] = this->adjMat[i][j] - otherG[i][j];
    }
}

subGraph.loadGraph(sub);
return subGraph;
}   



Graph& Graph::operator-=(const Graph& other) {   // Graph-=other
    
    if(!sizeCheck(*this, other)){
        throw invalid_argument("The graphs are not of the same dimensions.");
    }

const vector<vector<int>> &otherG = other.getGraph();
int size = otherG.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
        this->adjMat[i][j] -= otherG[i][j];
    }
}
return *this;
}   



Graph& Graph::operator++(){                    //++Graph

if(!this->is_loaded){
    throw invalid_argument("The graph isn't loaded .");
}
size_t size =this->adjMat.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
        if(this->adjMat[i][j]!=0){    //there is an edge
            this->adjMat[i][j] += 1;
        }
    }
}
return *this;
}



Graph Graph::operator++(int){                  //Graph++

if (!this->is_loaded) {
    throw invalid_argument("The graph isn't loaded .");
}

Graph old = *this;
++(*this);
return old;
}



Graph& Graph::operator--(){ //--Graph

if(!this->is_loaded){
    throw invalid_argument("The graph isn't loaded .");
}

size_t size =this->adjMat.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
        if(this->adjMat[i][j]!=0){    //there is an edge
            this->adjMat[i][j] -= 1;
        }
    }
}
return *this;
}               


Graph& Graph::operator*=(const double scalar){              // Graph*=scalar

if (!this->is_loaded) {
    throw invalid_argument("The graph isn't loaded .");
}
int size =this->adjMat.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
            this->adjMat[i][j] *= scalar;        // Multiply each edge weight by the scalar
    }
}
return *this;
}



Graph& Graph::operator*=(const Graph& other){               // Graph*=other

if(!sizeCheck(*this, other)){
        throw invalid_argument("The graphs are not of the same dimensions.");
    }

size_t size =this->adjMat.size();
const vector<vector<int>> &otherG = other.getGraph();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
            this->adjMat[i][j] *= otherG[i][j];        // Multiply each edge weight by the scalar
    }
}
return *this;
}



Graph& Graph::operator/=(const double scalar){               // Graph/=scalar

if (!this->is_loaded) {
    throw invalid_argument("The graph isn't loaded .");
}
size_t size =this->adjMat.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
            this->adjMat[i][j] /= scalar;        // Multiply each edge weight by the scalar
    }
}
return *this;
}



Graph Graph::operator--(int){                  //Graph--

if (!this->is_loaded) {
    throw invalid_argument("The graph isn't loaded .");
}

Graph old = *this;
--*this;
return old;
}



Graph& Graph::operator*(int scalar){           // Graph*scalar

if (!this->is_loaded) {
    throw invalid_argument("The graph isn't loaded .");
}
size_t size =this->adjMat.size();

for(size_t i = 0 ; i< size ; i++){
    for(size_t j = 0 ; j< size ; j++){
            this->adjMat[i][j] *= scalar;        // Multiply each edge weight by the scalar
    }
}
return *this;
}

Graph Graph::operator*(const Graph& other) {  // Graph * other

    // Check if matrices can be multiplied
    if (this->adjMat[0].size() != other.getGraph().size()) {
        throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    if (!this->is_loaded || !other.isLoaded()) {
        throw invalid_argument("One or both graphs are not loaded.");
    }

    // Get dimensions for matrix multiplication
    size_t row = this->adjMat.size();                  
    size_t col = other.getGraph()[0].size();           
    size_t innerDim = this->adjMat[0].size();          

    Graph multiply;                                   
    vector<vector<int>> multi(row, vector<int>(col, 0));   // Initialize result matrix 

    const vector<vector<int>>& otherG = other.getGraph(); // Reference to the adjacency matrix of the other graph

    // Perform matrix multiplication
    for(size_t i = 0; i < row; i++) {                  
        for(size_t j = 0; j < col; j++) {              
            for(size_t k = 0; k < innerDim; k++) {      // Loop over the inner dimension (columns of the first, rows of the second)
                multi[i][j] += this->adjMat[i][k] * otherG[k][j];  // Matrix multiplication formula
            }
        }
    }

    multiply.loadGraph(multi);  // Load the resulting matrix into the multiply graph
    return multiply;            
}



bool Graph::operator==(const Graph& other) const{   //Graph==other

if(!sizeCheck(*this, other)){
    throw invalid_argument("The graphs are not of the same dimensions.");
}

const vector<vector<int>> &otherG = other.getGraph();
size_t size = otherG.size();

for(size_t i = 0 ; i < size ; i++){
    for(size_t j = 0 ; j < size ; j++){
        if(this->adjMat[i][j] != otherG[i][j]){
            return false;
        }
    }
}
return true;
}



bool Graph::operator!=(const Graph& other) const{   //Graph!=other
    return !(*this == other);                       //will return true in case the graphs are not equals
}



bool Graph::operator>(const Graph& other) const { // Graph > other

    if (!this->is_loaded || !other.isLoaded()) {
        throw std::invalid_argument("One or both graphs are not loaded.");
    }

    // Check if graphs are the same size
    if (!sizeCheck(*this, other)) {
        throw std::invalid_argument("The graphs are not of the same dimensions.");
    }

    size_t thisEdges = this->numEdges();  // Number of edges in the current graph
    size_t otherEdges = other.numEdges(); // Number of edges in the other graph

    // If Graph has more edges than the other
    if (thisEdges != otherEdges) {
        return thisEdges > otherEdges;
    }

    // If the number of edges is the same, compare the number of vertices (dimensions)
    return this->adjMat.size() > other.getGraph().size();
}

bool Graph::operator<(const ariel::Graph& other) const{
    return !(*this >= other);
}


bool Graph::operator<=(const Graph& other) const{  //Graph<=other
    return *this<other || *this==other ;
}



bool Graph::operator>=(const Graph& other) const{  //Graph>=other
    return *this>other || *this==other;
}




// Graph is contained in other: if Graph has more or equal vertices than other and has the same wigheted edges
bool Graph::isContained(const Graph& other) const{   //Graph contains other

if(!other.isLoaded() || !this->is_loaded){
    throw invalid_argument("One or both graphs are not loaded.");
}

const vector<vector<int>> &otherG = other.getGraph();
const vector<vector<int>> &thisG = this->adjMat;

if(otherG.size() > thisG.size()){     
    return false;
}

for(size_t i = 0 ; i< otherG.size() ; i++){
    for(size_t j = 0 ; j< otherG.size() ; j++){

        //If there is an edge in otherG and the value isn't equal
        if(otherG[i][j] != 0 && otherG[i][j] != thisG[i][j]){
                return false;
            }
        }
    }

return true;

}




bool Graph::sizeCheck(const Graph& graph1, const Graph& graph2) const {

if(!graph1.isLoaded() || !graph2.isLoaded()){            //check if the graph has been loaded
    throw invalid_argument("One or both graphs are not loaded");  //and if each of the graphs is in the form n*n
}

const vector<vector<int>>& g1= graph1.getGraph();
const vector<vector<int>>& g2 = graph2.getGraph();


return (g1.size() == g2.size())&&(g1[0].size() == g1.size());
}



size_t Graph::numEdges() const{

if(!this->isLoaded()){
    throw invalid_argument("The graph is not loaded");
}

size_t edges = 0;
size_t size = this->adjMat.size();

for(size_t i = 0; i < size ; i++){
    for(size_t j = 0; j < size ; j++){
        if(adjMat[i][j]!= 0){
            edges++;
        }
    }
}

return edges;
}

