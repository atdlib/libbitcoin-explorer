/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SX_EC_MULTIPLY_HPP
#define SX_EC_MULTIPLY_HPP

#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <sx/command.hpp>
#include <sx/define.hpp>
#include <sx/generated.hpp>
#include <sx/utility/byte.hpp>
#include <sx/utility/bytes.hpp>
#include <sx/utility/compat.hpp>
#include <sx/utility/config.hpp>
#include <sx/utility/console.hpp>

/********* GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY **********/

namespace sx {
namespace extensions {

/**
 * Various localizable strings.
 */
#define SX_EC_MULTIPLY_INVALID_POINT \
    "Invalid point '%1%'."
#define SX_EC_MULTIPLY_INVALID_INTEGER \
    "Invalid secret '%1%'."
#define SX_EC_MULITPLY_OUT_OF_RANGE \
    "Product exceeds valid range."

/**
 * Class to implement the sx ec-multiply command.
 */
class ec_multiply 
    : public command
{
public:

    /**
     * The symbolic (not localizable) command name, lower case.
     */
    static const char* symbol() { return "ec-multiply"; }

    /**
     * The member symbolic (not localizable) command name, lower case.
     */
    const char* name()
    {
        return ec_multiply::symbol();
    }

    /**
     * The localizable command category name, upper case.
     */
    const char* category()
    {
        return "UTILITY";
    }

    /**
     * The localizable command subcategory name, upper case.
     */
    const char* subcategory()
    {
        return "EC MATH";
    }

    /**
     * DEPRECATED
     * The localizable command description, multiple lines, punctuated.
     */
    const std::vector<const char*> description()
    {
        return
        {
        };
    }

    /**
     * DEPRECATED
     * The non-localizable command usage examples, multiple lines.
     */
    const std::vector<const char*> example()
    {
        return
        {
        };
    }

    /**
     * DEPRECATED
     * The localizable command explanation, multiple lines, punctuated.
     */
    const std::vector<const char*> explanation()
    {
        return
        {
        };
    }

    /**
     * Load program argument definitions.
     * A value of -1 indicates that the number of instances is unlimited.
     *
     * @return  The loaded program argument definitions.
     */
    arguments_metadata& load_arguments()
    {
        return get_argument_metadata()
            .add("POINT", 1)
            .add("SECRET", 1);
    }
    
    /**
     * Load program option definitions.
     * The implicit_value call allows flags to be strongly-typed on read while
     * allowing but not requiring a value on the command line for the option.
     *
     * BUGBUG: see boost bug/fix: svn.boost.org/trac/boost/ticket/8009
     *
     * @return  The loaded program option definitions.
     */
    options_metadata& load_options()
    {
        using namespace po;
        options_description& options = get_option_metadata();
        options.add_options()
            (
                SX_VARIABLE_CONFIG ",c",
                value<boost::filesystem::path>(),                 
                "The path and file name for the configuration settings file for this application."
            )
            (
                "help,h",
                value<bool>(&option_.help)->implicit_value(true),
                "Calculate the elliptic curve product (POINT * SECRET)."
            )
            (
                "POINT",
                value<bytes>(&argument_.point),
                "A point to multiply."
            )
            (
                "SECRET",
                value<bytes>(&argument_.secret),
                "A secret to multiply."
            );

        return options;
    }
	
	/**
     * Load streamed value as parameter fallback.
     *
     * @param[in]  input  The input stream for loading the parameter.
     * @param[in]         The loaded variables.
     */
    void load_stream(std::istream& input,
        boost::program_options::variables_map& variables)
    {
    }

    /**
     * Invoke the command.
     *
     * @param[in]   input   The input stream for the command execution.
     * @param[out]  output  The input stream for the command execution.
     * @param[out]  error   The input stream for the command execution.
     * @return              The appropriate console return code { -1, 0, 1 }.
     */
    virtual console_result invoke(std::istream& input, std::ostream& output,
        std::ostream& cerr);
        
    /* Properties */

    /**
     * Get the value of the POINT argument.
     */
    virtual bytes get_point_argument()
    {
        return argument_.point;
    }
    
    /**
     * Set the value of the POINT argument.
     */
    virtual void set_point_argument(bytes value)
    {
        argument_.point = value;
    }

    /**
     * Get the value of the SECRET argument.
     */
    virtual bytes get_secret_argument()
    {
        return argument_.secret;
    }
    
    /**
     * Set the value of the SECRET argument.
     */
    virtual void set_secret_argument(bytes value)
    {
        argument_.secret = value;
    }

    /**
     * Get the value of the help option.
     */
    virtual bool get_help_option()
    {
        return option_.help;
    }
    
    /**
     * Set the value of the help option.
     */
    virtual void set_help_option(bool value)
    {
        option_.help = value;
    }

private:

    /**
     * Command line argument bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct argument
    {
        argument()
          : point(),
            secret()
            {}
        bytes point;
        bytes secret;
    } argument_;
    
    /**
     * Command line option bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct option
    {
        option()
          : help()
            {}    
        bool help;
    } option_;
};

} // extensions
} // sx

#endif
