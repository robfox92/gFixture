#include <iostream>
#include "docopt.cpp"


static const char USAGE[] =
R"(
    Graph Fixturing.
    Uses maximally weighted matching to provide a fixture for a league
    Supports Google Sheets-stored scores, ladders and previous fixtures

    Usage:
        gFixture leagueName <name> sheet <url>

    Options:
        -h  --help                      Show this screen
        --rematchCount=<rematchCount>   Allowed rematch count [default: 0]
        --round=<roundNumber>           Round Number to apply to the output file
)";


int main(int argc, const char** argv)
{
    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc },
                         true,               // show help if requested
                         "gFixture 0.1");  // version string

    for(auto const& arg : args) {
        std::cout << arg.first << " : "<<  arg.second << std::endl;
    }

    return 0;
    
}