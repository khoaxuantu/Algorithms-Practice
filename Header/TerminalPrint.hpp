#if !defined(TERMINALPRINT_HPP)
#define TERMINALPRINT_HPP

template <typename _DataType>
class TerminalPrint
{
private:
public:
    static void print2dArray(_DataType dp) {
        for (auto arr : dp) {
            for (auto i : arr) cout << i << " ";
            cout << endl;
        }
    }
};


#endif // TERMINALPRINT_HPP
