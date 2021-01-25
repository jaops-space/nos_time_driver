/* Copyright (C) 2009 - 2021 National Aeronautics and Space Administration. All Foreign Rights are Reserved to the U.S. Government.

This software is provided "as is" without any warranty of any, kind either express, implied, or statutory, including, but not
limited to, any warranty that the software will conform to, specifications any implied warranties of merchantability, fitness
for a particular purpose, and freedom from infringement, and any warranty that the documentation will conform to the program, or
any warranty that the software will be error free.

In no event shall NASA be liable for any damages, including, but not limited to direct, indirect, special or consequential damages,
arising out of, resulting from, or in any way connected with the software or its documentation.  Whether or not based upon warranty,
contract, tort or otherwise, and whether or not loss was sustained from, or arose out of the results of, or use of, the software,
documentation or services provided hereunder

ITC Team
NASA IV&V
ivv-itc@lists.nasa.gov
*/

/* Standard Includes */
#include <string>

#include <boost/property_tree/ptree.hpp>

#include <Client/Bus.hpp>

#include <sim_i_hardware_model.hpp>

namespace Nos3
{
    /** \brief Class to drive NOS time.
     *
     */
    class TimeDriver : public SimIHardwareModel
    {
    public:
        /*************************************************************************
         * Constructors / destructors
         *************************************************************************/

        TimeDriver(const boost::property_tree::ptree& config);

        /*************************************************************************
         * Mutating public worker methods
         *************************************************************************/

        void run(void);

    private:
        // Private data
        const bool                                     _active;
        const int64_t                                  _real_microseconds_per_tick;

        std::string                                    _time_uri;
        std::string                                    _time_bus_name;
        unsigned int                                   _time_counter;
        std::unique_ptr<NosEngine::Client::Bus>        _time_bus;
    };
}
