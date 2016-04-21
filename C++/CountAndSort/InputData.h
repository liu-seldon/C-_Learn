class InputData {
    public:
    char data;
    int count;
    int order;

    bool operator<(const InputData& a)const {
        bool result = false;
        if(this->count < a.count) {
            result = true;
        } else if (this->count > a.count) {
            result = false;
        } else {
            result = this->order > a.order; 
        }
        return result;
    }
    
    bool operator==(const InputData& a) const {
        return this->data == a.data;
    }
};

class InputDataCmpByOrder {
    public:
        bool operator()(const InputData& a, const InputData& b) {
            bool result = false;
            if(a.count > b.count) {
                result = true;
            } else if (a.count < b.count) {
                result = false;
            } else {
                result = a.order < b.order; 
            }
            return result;
        }
};

