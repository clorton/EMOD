/***************************************************************************************************

Copyright (c) 2015 Intellectual Ventures Property Holdings, LLC (IVPH) All rights reserved.

EMOD is licensed under the Creative Commons Attribution-Noncommercial-ShareAlike 4.0 License.
To view a copy of this license, visit https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode.

***************************************************************************************************/

#include "stdafx.h"
#include "Configuration.h"
#include "ConfigurationImpl.h"
#include "Configure.h"
#include "Exceptions.h"
#include "IdmString.h"
#include "Log.h"

static const char * _module = "JsonConfigurable";

namespace Kernel
{
    /// NodeSetConfig
    NodeSetConfig::NodeSetConfig()
    {}

    NodeSetConfig::NodeSetConfig(json::QuickInterpreter* qi)
    : _json(*qi)
    {
    }

    json::QuickBuilder 
    NodeSetConfig::GetSchema()
    {
        json::QuickBuilder schema( jsonSchemaBase );
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:NodeSet" );
        schema[ ts ]= json::Object();
        schema[ ts ][ "base" ] = json::String( "interventions.idmType.NodeSet" );
        //json::Writer::Write( schema, std::cout );
        return schema;
    }

    void
    NodeSetConfig::ConfigureFromJsonAndKey(
        const Configuration* inputJson,
        const std::string& key
    )
    {
        if( !inputJson->Exist( key ) )
        {
            throw MissingParameterFromConfigurationException( __FILE__, __LINE__, __FUNCTION__, "campaign.json", key.c_str() );
        }

        _json = (*inputJson)[key];
        //std::cout << "NodeSetConfig::Configure called with json blob." << std::endl;
        //json::Writer::Write( _json, std::cout ); 
    }

    /// END NodeSetConfig
 
    /// EventConfig
    EventConfig::EventConfig()
    {}

    EventConfig::EventConfig(json::QuickInterpreter* qi)
        : _json(*qi)
    {
    }

    void
    EventConfig::ConfigureFromJsonAndKey(
        const Configuration* inputJson,
        const std::string& key
    )
    {
        if( !inputJson->Exist( key ) )
        {
            throw MissingParameterFromConfigurationException( __FILE__, __LINE__, __FUNCTION__, "campaign.json", key.c_str() );
        }
        _json = (*inputJson)[key];
        //std::cout << "EventConfig::Configure called with json blob." << std::endl;
        //json::Writer::Write( _json, std::cout );
    }

    json::QuickBuilder 
    EventConfig::GetSchema()
    {
        json::QuickBuilder schema( jsonSchemaBase );
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:EventCoordinator" );
        schema[ ts ]= json::Object();
        schema[ ts ][ "base" ] = json::String( "interventions.idmType.EventCoordinator" );
        //json::Writer::Write( schema, std::cout );
        return schema;
    }

    /// InterventionConfig
    InterventionConfig::InterventionConfig()
    //: _qi( _json )
    {}

    InterventionConfig::InterventionConfig(json::QuickInterpreter* qi)
        : _json(*qi)
        //, _qi(*qi)
    {
        //json::Writer::Write( _json, std::cout );
        //std::cout << "Yay, we can write out our _json!" << std::endl;
    }

    void
    InterventionConfig::ConfigureFromJsonAndKey(
        const Configuration* inputJson,
        const std::string& key
    )
    {
        if( !inputJson->Exist( key ) )
        {
            throw MissingParameterFromConfigurationException( __FILE__, __LINE__, __FUNCTION__, "campaign.json", key.c_str() );
        }
        // we need to set _json to inputJson
        _json = (*inputJson)[key];

        // This might be useful for debugging, but couldn't agree on how to whether to include or not. Uncomment if you need it.
        /*std::ostringstream msg;
        msg << "InterventionConfig::" << __FUNCTION__ << " called with json blob." << std::endl;
        json::Writer::Write( _json, msg ); 
        LOG_DEBUG_F( "%s", msg.str().c_str() );*/
    }

    json::QuickBuilder 
    InterventionConfig::GetSchema()
    {
        json::QuickBuilder schema( jsonSchemaBase );
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:Intervention" );
        schema[ ts ]= json::Object();
        schema[ ts ][ "base" ] = json::String( "interventions.idmAbstractType.Intervention" );
        //json::Writer::Write( schema, std::cout );
        return schema;
    }

    template < class Archive >
    void serialize( Archive &ar, InterventionConfig& config, unsigned int file_version )
    {
        ar & config._json;
    }

    IndividualInterventionConfig::IndividualInterventionConfig()
    {
    }

    json::QuickBuilder 
    IndividualInterventionConfig::GetSchema()
    {
        json::QuickBuilder schema = InterventionConfig::GetSchema();
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:IndividualIntervention" );
        schema[ ts ][ "base" ] = json::String( "interventions.idmAbstractType.IndividualIntervention" );
        return schema;
    }

    json::QuickBuilder 
    NodeInterventionConfig::GetSchema()
    {
        json::QuickBuilder schema = InterventionConfig::GetSchema();
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:NodeIntervention" );
        schema[ ts ][ "base" ] = json::String( "interventions.idmAbstractType.NodeIntervention" );
        return schema;
    }

    /// END OF InterventionConfig


    /// WaningConfig
    WaningConfig::WaningConfig()
    {}

    WaningConfig::WaningConfig(json::QuickInterpreter* qi)
    : _json(*qi)
    {
    }

    json::QuickBuilder 
    WaningConfig::GetSchema()
    {
        json::QuickBuilder schema( jsonSchemaBase );
        auto tn = JsonConfigurable::_typename_label();
        auto ts = JsonConfigurable::_typeschema_label();
        schema[ tn ] = json::String( "idmType:WaningEffect" );
        schema[ ts ]= json::Object();
        schema[ ts ][ "base" ] = json::String( "interventions.idmType.Waning" );
        //json::Writer::Write( schema, std::cout );
        return schema;
    }

    void
    WaningConfig::ConfigureFromJsonAndKey(
        const Configuration* inputJson,
        const std::string& key
    )
    {
        if( !inputJson->Exist( key ) )
        {
            throw MissingParameterFromConfigurationException( __FILE__, __LINE__, __FUNCTION__, "campaign.json", key.c_str() );
        }
        _json = (*inputJson)[key];
        //std::cout << "WaningConfig::Configure called with json blob." << std::endl;
        //json::Writer::Write( _json, std::cout ); 
    }

    /// END WaningConfig

    std::map< std::string, IJsonConfigurable* > IJsonConfigurable::generic_container;

    JsonConfigurable::ConstrainedString::ConstrainedString( std::string &init_str )
    : constraint_param(nullptr)
    {
        *((std::string*)(this)) = init_str;
    }

    JsonConfigurable::ConstrainedString::ConstrainedString( const char* init_str )
    : constraint_param(nullptr)
    {
        *((std::string*)(this)) = std::string( init_str );
    }

    const JsonConfigurable::ConstrainedString&
    JsonConfigurable::ConstrainedString::operator=( const std::string& new_value )
    {
        *((std::string*)(this)) = new_value;
        //release_assert( constraint_param );
        if( constraint_param && constraint_param->count( new_value ) == 0 )
        {
            std::ostringstream msg;
            msg << "Constrained String" ;
            if( !parameter_name.empty() )
            {
                msg << " (" << parameter_name << ")" ;
            }
            msg << " with specified value " 
                << new_value 
                << " invalid. Possible values are: " << std::endl ;
            for( auto value : (*constraint_param) )
            {
                msg << value << std::endl;
            }
            throw GeneralConfigurationException( __FILE__, __LINE__, __FUNCTION__, msg.str().c_str() );
        }
        return *this ;
    }

    template < class Archive >
    void serialize( Archive &ar, JsonConfigurable::ConstrainedString& cs, unsigned int file_version )
    {
        //ar & cs.;
    }

    const char * JsonConfigurable::default_description = "No Description Yet";
    const char * JsonConfigurable::default_string = "UNINITIALIZED STRING";
    bool JsonConfigurable::_dryrun = false;
    bool JsonConfigurable::_useDefaults = true;
    bool JsonConfigurable::_track_missing = true;
    bool JsonConfigurable::_possibleNonflatConfig = false;
    std::set< std::string > JsonConfigurable::empty_set;

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        bool * pVariable,
        const char* description,
        bool defaultvalue
    )
    {
        LOG_DEBUG_F("initConfigTypeMap<bool>: %s\n", paramName);
        boolConfigTypeMap[ paramName ] = pVariable;
        json::Object newIntSchema;
        newIntSchema["description"] = json::String(description);
        newIntSchema["type"] = json::String( "bool" );
        /* Use this when boolean configuration parameters are actually 'true'/'false'.
        newIntSchema["default"] = json::Boolean(defaultvalue); */
        newIntSchema["default"] = json::Number(defaultvalue ? 1 : 0);
        jsonSchemaBase[paramName] = newIntSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        int * pVariable,
        const char * description,
        int min, int max, int defaultvalue,
        const char* condition_key, const char* condition_value
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<int>: %s\n", paramName);
        intConfigTypeMap[ paramName ] = pVariable;
        json::Object newIntSchema;
        newIntSchema["description"] = json::String(description);
        newIntSchema["type"] = json::String( "integer" );
        newIntSchema["min"] = json::Number(min);
        newIntSchema["max"] = json::Number(max);
        newIntSchema["default"] = json::Number(defaultvalue);
        if( condition_key && condition_value )
        {
            json::Object condition;
            condition[ condition_key ] = json::String( condition_value );
            newIntSchema["depends-on"] = condition;
        }
        jsonSchemaBase[paramName] = newIntSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        float * pVariable,
        const char * description,
        float min, float max, float defaultvalue,
        const char* condition_key, const char* condition_value
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<float>: %s\n", paramName);
        floatConfigTypeMap[ paramName ] = pVariable;
        json::Object newFloatSchema;
        newFloatSchema["description"] = json::String(description);
        newFloatSchema["type"] = json::String( "float" );
        newFloatSchema["min"] = json::Number(min);
        newFloatSchema["max"] = json::Number(max);
        newFloatSchema["default"] = json::Number(defaultvalue);
        if( condition_key && condition_value )
        {
            json::Object condition;
            condition[ condition_key ] = json::String( condition_value );
            newFloatSchema["depends-on"] = condition;
        }
        jsonSchemaBase[paramName] = newFloatSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        double * pVariable,
        const char * description,
        double min, double max, double defaultvalue
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<double>: %s\n", paramName);
        doubleConfigTypeMap[ paramName ] = pVariable;
        json::Object newDoubleSchema;
        newDoubleSchema["description"] = json::String(description);
        newDoubleSchema["type"] = json::String("double");
        newDoubleSchema["min"] = json::Number(min);
        newDoubleSchema["max"] = json::Number(max);
        newDoubleSchema["default"] = json::Number(defaultvalue);
        jsonSchemaBase[paramName] = newDoubleSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        std::string * pVariable,
        const char * description,
        const std::string& default_str
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<string>: %s\n", paramName);
        json::Object newStringSchema;
        newStringSchema["default"] = json::String(default_str);
        newStringSchema["description"] = json::String(description);
        newStringSchema["type"] = json::String("string");
        stringConfigTypeMap[ paramName ] = pVariable;
        jsonSchemaBase[paramName] = newStringSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        ConstrainedString * pVariable,
        const char * description,
        const std::string& default_str
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<ConstrainedString>: %s\n", paramName);
        json::Object newConStringSchema;
        newConStringSchema["default"] = json::String(default_str); // would be nice if this always in the constraint list!
        newConStringSchema["description"] = json::String(description);
        newConStringSchema["type"] = json::String("Constrained String");
        newConStringSchema["value_source"] = json::String( pVariable->constraints );
        conStringConfigTypeMap[ paramName ] = pVariable;
        jsonSchemaBase[paramName] = newConStringSchema;
    }


    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        tStringSetBase * pVariable,
        const char* description,
        const char* condition_key,
        const char* condition_value
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<set<string>>: %s\n", paramName);
        stringSetConfigTypeMap[ paramName ] = pVariable;
        json::Object root;
        json::QuickBuilder newStringSetSchema( root );
        newStringSetSchema["description"] = json::String(description);
        newStringSetSchema["type"] = json::String( pVariable->getTypeName() );
        newStringSetSchema["default"] = json::Array();
        unsigned int counter = 0;
        if( pVariable->getTypeName() == FIXED_STRING_SET_LABEL )
        {
            newStringSetSchema["possible_values"] = json::Array();
            for( auto& value : ((tFixedStringSet*)pVariable)->possible_values )
            {
                newStringSetSchema["possible_values"][counter++] = json::String( value );
            }
        }
        else if( pVariable->getTypeName() == DYNAMIC_STRING_SET_LABEL )
        {
            newStringSetSchema["value_source"] = json::String( ((tDynamicStringSet*)pVariable)->value_source );
        }
        else
        {
            // just a regular old string set, no problem.
        }

        if( condition_key && condition_value )
        {
            json::Object condition;
            condition[ condition_key ] = json::String( condition_value );
            newStringSetSchema["depends-on"] = condition;
        }
        jsonSchemaBase[paramName] = newStringSetSchema.As<json::Object>();
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        std::vector< std::string > * pVariable,
        const char* description,
        const char* constraint_schema,
        const std::set< std::string > &constraint_variable
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<vector<string>>: %s\n", paramName);
        vectorStringConfigTypeMap[ paramName ] = pVariable;
        vectorStringConstraintsTypeMap[ paramName ] = &constraint_variable;
        json::Object newVectorStringSchema;
        newVectorStringSchema["description"] = json::String(description);
        newVectorStringSchema["type"] = json::String("vector string");
        if( constraint_schema )
        {
            newVectorStringSchema["value_source"] = json::String( constraint_schema );
        }
        jsonSchemaBase[paramName] = newVectorStringSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        std::vector< float > * pVariable,
        const char* description,
        float min, float max, float defaultvalue
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<vector<float>>: %s\n", paramName);
        vectorFloatConfigTypeMap[ paramName ] = pVariable;
        json::Object newVectorFloatSchema;
        newVectorFloatSchema["description"] = json::String(description);
        newVectorFloatSchema["type"] = json::String("vector float");
        newVectorFloatSchema["min"] = json::Number(min);
        newVectorFloatSchema["max"] = json::Number(max);
        newVectorFloatSchema["default"] = json::Number(defaultvalue);
        jsonSchemaBase[paramName] = newVectorFloatSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        std::vector< std::vector< float > > * pVariable,
        const char* description,
        float min, float max, float defaultvalue
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<vector,vector<float>>>: %s\n", paramName);
        vector2dFloatConfigTypeMap[ paramName ] = pVariable;
        json::Object newVector2dFloatSchema;
        newVector2dFloatSchema["description"] = json::String(description);
        newVector2dFloatSchema["type"] = json::String("vector2d float");
        newVector2dFloatSchema["min"] = json::Number(min);
        newVector2dFloatSchema["max"] = json::Number(max);
        newVector2dFloatSchema["default"] = json::Number(defaultvalue);
        jsonSchemaBase[paramName] = newVector2dFloatSchema;
    }

    // We have sets/vectors from json arrays, now add maps from json dictonaries
    // This will be for specific piece-wise constant maps of dates (fractional years)
    // to config values (floats first).
    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        tFloatFloatMapConfigType * pVariable,
        const char* defaultDesc
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<pwcMap>: %s\n", paramName);
        ffMapConfigTypeMap[ paramName ] = pVariable;
        json::Object newNestedSchema;
        newNestedSchema["description"] = json::String(defaultDesc);
        newNestedSchema["type"] = json::String("nested json object (of key-value pairs)");
        jsonSchemaBase[paramName] = newNestedSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        tFloatFloatMapConfigType * pVariable,
        const char* description,
        const char* condition_key, const char* condition_value
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<pwcMap>: %s\n", paramName);
        ffMapConfigTypeMap[ paramName ] = pVariable;
        json::Object newNestedSchema;
        newNestedSchema["description"] = json::String(description);
        newNestedSchema["type"] = json::String("nested json object (of key-value pairs)");
        if( condition_key && condition_value )
        {
            json::Object condition;
            condition[ condition_key ] = json::String( condition_value );
            newNestedSchema["depends-on"] = condition;
        }
        jsonSchemaBase[paramName] = newNestedSchema;
    }

    void
    JsonConfigurable::initConfigTypeMap(
        const char* paramName,
        tStringFloatMapConfigType * pVariable,
        const char* defaultDesc
    )
    {
        LOG_DEBUG_F( "initConfigTypeMap<pwcMap>: %s\n", paramName);
        sfMapConfigTypeMap[ paramName ] = pVariable;
        json::Object newNestedSchema;
        newNestedSchema["description"] = json::String(defaultDesc);
        newNestedSchema["type"] = json::String("nested json object (of key-value pairs)");
        jsonSchemaBase[paramName] = newNestedSchema;
    }


    bool JsonConfigurable::Configure( const Configuration* inputJson )
    {
        //if( getenv( "DRYRUN" ) )
        if( _dryrun )
        {
            LOG_DEBUG("Returning from Configure because doing dryrun\n");
            return true;
        }

        // INIT STAGE
        // initVarFromConfig: iterate over all config keys...
        // until we figure that out, go the other way

        // ---------------------------------- BOOL ------------------------------------
        for (auto& entry : boolConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];

            // check if parameter was specified in input json (TODO: improve performance by getting the iterator here with Find() and reusing instead of GET_CONFIG_BOOLEAN below)
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                // using the default value
                /* Use this when boolean configuration parameters are actually 'true'/'false'.
                bool defaultValue = (bool)schema["default"].As<json::Boolean>();*/
                bool defaultValue = ((int)schema["default"].As<json::Number>() == 1);
                *(entry.second) = defaultValue;
                LOG_INFO_F( "Using the default value ( \"%s\" : %d ) for unspecified parameter.\n", key.c_str(), defaultValue );
                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                *(entry.second) = (bool)GET_CONFIG_BOOLEAN(inputJson,key.c_str());
            }

            LOG_DEBUG_F("the key %s = bool %d\n", key.c_str(), *(entry.second));
        }

        // ---------------------------------- INT -------------------------------------
        for (auto& entry : intConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            int val = -1;

            // check if parameter was specified in input json (TODO: improve performance by getting the iterator here with Find() and reusing instead of GET_CONFIG_INTEGER below)
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                // using the default value
                val = (int)schema["default"].As<json::Number>();
                LOG_INFO_F( "Using the default value ( \"%s\" : %d ) for unspecified parameter.\n", key.c_str(), val );
                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                double jsonValueAsDouble = GET_CONFIG_DOUBLE( inputJson, key.c_str() );
                if( jsonValueAsDouble != (int) jsonValueAsDouble )
                {
                    std::ostringstream errMsg; // using a non-parameterized exception.
                    errMsg << "Value from json appears to be decimal ("
                           << jsonValueAsDouble
                           << ") but needs to be integer." << std::endl;
                    throw Kernel::GeneralConfigurationException( __FILE__, __LINE__, __FUNCTION__, errMsg.str().c_str() );
                }
                // get specified configuration parameter
                val = (int)GET_CONFIG_INTEGER(inputJson,key.c_str());
            }

            // throw exception if value is outside of range
            EnforceParameterRange<int>( key, val, schema );

            *(entry.second) = val;

            LOG_DEBUG_F("the key %s = int %d\n", key.c_str(), *(entry.second));
        }

        // ---------------------------------- FLOAT ------------------------------------
        for (auto& entry : floatConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            float val = -1.0f;

            // Check if parameter was specified in input json (TODO: improve performance by getting the iterator here with Find() and reusing instead of GET_CONFIG_DOUBLE below)
            LOG_DEBUG_F( "useDefaults = %d\n", _useDefaults );
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                // using the default value
                val = (float)schema["default"].As<json::Number>();
                LOG_INFO_F( "Using the default value ( \"%s\" : %f ) for unspecified parameter.\n", key.c_str(), val );
                if( _track_missing ) // EAW: umm... don't we want to also track missing even if useDefaults is FALSE!
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                // get specified configuration parameter
                val = (float) GET_CONFIG_DOUBLE( inputJson, key.c_str() );
            }

            // throw exception if specified value is outside of range
            EnforceParameterRange<float>( key, val, schema);

            *(entry.second) = val;

            LOG_DEBUG_F("the key %s = float %f\n", key.c_str(), *(entry.second));
        }

        // ---------------------------------- DOUBLE ------------------------------------
        for (auto& entry : doubleConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            double val = -1.0;

            // Check if parameter was specified in input json (TODO: improve performance by getting the iterator here with Find() and reusing instead of GET_CONFIG_DOUBLE below)
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                // using the default value
                val = schema["default"].As<json::Number>();
                LOG_INFO_F( "Using the default value ( \"%s\" : %f ) for unspecified parameter.\n", key.c_str(), val );
                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                // get specified configuration parameter
                val = GET_CONFIG_DOUBLE( inputJson, key.c_str() );
            }

            // throw exception if specified value is outside of range
            EnforceParameterRange<double>( key, val, schema);

            *(entry.second) = val;

            LOG_DEBUG_F("the key %s = double %f\n", key.c_str(), *(entry.second));
        }

        // ---------------------------------- STRING ------------------------------------
        for (auto& entry : stringConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            std::string val = schema["default"].As<json::String>();
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                LOG_INFO_F( "Using the default value ( \"%s\" : \"%s\" ) for unspecified parameter.\n", key.c_str(), val.c_str() );
                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                val = (std::string) GET_CONFIG_STRING( inputJson, (entry.first).c_str() );
            }
            *(entry.second) = val;
        }

        for (auto& entry : conStringConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            std::string val = schema["default"].As<json::String>();
            if ( !inputJson->Exist(key) && _useDefaults )
            {
                LOG_INFO_F( "Using the default value ( \"%s\" : %f ) for unspecified parameter.\n", key.c_str(), val.c_str() );
                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                val = (std::string) GET_CONFIG_STRING( inputJson, (entry.first).c_str() );
            }
            *(entry.second) = val;
        }

        // ---------------------------------- SET of STRINGs ------------------------------------
        for (auto& entry : stringSetConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            if ( !inputJson->Exist(key) )
            {
                if( _useDefaults )
                {
                    // using the default value
                    auto val = schema["default"].As<json::Array>();
                    LOG_INFO_F( "Using the default value ( \"%s\" : <empty string set> ) for unspecified string set parameter.\n", key.c_str() );
                }

                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                *(entry.second) = GET_CONFIG_STRING_SET( inputJson, (entry.first).c_str() );
                // TODO: validate against value_source
            }
        }

        // ---------------------------------- VECTOR of STRINGs ------------------------------------
        for (auto& entry : vectorStringConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            if ( !inputJson->Exist(key) )
            {
                if( _useDefaults )
                {
                    // using the default value
                    LOG_INFO_F( "Using the default value ( \"%s\" : <empty string vector> ) for unspecified string vector parameter.\n", key.c_str() );
                }

                if( _track_missing )
                {
                    missing_parameters_set.insert(key);
                }
            }
            else
            {
                *(entry.second) = GET_CONFIG_VECTOR_STRING( inputJson, (entry.first).c_str() );
            }
            auto allowed_values = vectorStringConstraintsTypeMap[ key ];
            for( auto &candidate : *(entry.second) )
            {
                if( allowed_values->size() > 0 && std::find( allowed_values->begin(), allowed_values->end(), candidate ) == allowed_values->end() )
                {
                    std::ostringstream msg;
                    msg << "Constrained strings (dynamic enum) with specified value " 
                        << candidate 
                        << " invalid. Possible values are: ";
                    for( auto value: *allowed_values )
                    {
                        msg << value << "...";
                    }
                    throw GeneralConfigurationException( __FILE__, __LINE__, __FUNCTION__, msg.str().c_str() );
                }
            }
        }

        //----------------------------------- VECTOR of FLOATs ------------------------------
        for (auto& entry : vectorFloatConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            if ( !inputJson->Exist(key) && _track_missing )
            {
                missing_parameters_set.insert(key);
            }
            else
            {
                std::vector<float> configValues = GET_CONFIG_VECTOR_FLOAT( inputJson, (entry.first).c_str() );
                *(entry.second) = configValues;

                EnforceVectorParameterRanges<float>(key, configValues, schema);
            }
        }

        //----------------------------------- VECTOR VECTOR of FLOATs ------------------------------
        for (auto& entry : vector2dFloatConfigTypeMap)
        {
            const std::string& key = entry.first;
            json::QuickInterpreter schema = jsonSchemaBase[key];
            if ( !inputJson->Exist(key) && _track_missing )
            {
                missing_parameters_set.insert(key);
            }
            else
            {
                std::vector<std::vector<float>> configValues = GET_CONFIG_VECTOR2D_FLOAT( inputJson, (entry.first).c_str() );
                *(entry.second) = configValues;

                for( auto values : configValues )
                {
                    EnforceVectorParameterRanges<float>(key, values, schema);
                }
            }
        }

        // Let's see if we can iterate over our template base class generic container!
        //std::cout << "IJsonConfigurable::generic_container.size() = " << IJsonConfigurable::generic_container.size() << std::endl;
        for( auto iter = IJsonConfigurable::generic_container.begin();
			 IJsonConfigurable::generic_container.size() > 0;
			 )
        {
            auto temp_cont = *iter;
			IJsonConfigurable::generic_container.erase( iter++ );
            temp_cont.second->Configure( inputJson );
        }

        // ---------------------------------- FLOAT-FLOAT MAP ------------------------------------
        for (auto& entry : ffMapConfigTypeMap)
        {
            // NOTE that this could be used for general float to float, but right now hard-coding year-as-int to float
            const auto & key = entry.first;
            tFloatFloatMapConfigType * pFFMap = entry.second;
            const auto& tvcs_jo = json_cast<const json::Object&>( (*inputJson)[key] );
            for( auto data = tvcs_jo.Begin();
                      data != tvcs_jo.End();
                      ++data )
            {
                float year = atof( data->name.c_str() );
                auto tvcs = inputJson->As< json::Object >()[ key ]; 
                float constant = (float) ((json::QuickInterpreter( tvcs ))[ data->name ].As<json::Number>());
                LOG_DEBUG_F( "Inserting year %f and delay %f into map.\n", year, constant );
                pFFMap->insert( std::make_pair( year, constant ) );
            }
        }

        // ---------------------------------- STRING-FLOAT MAP ------------------------------------
        for (auto& entry : sfMapConfigTypeMap)
        {
            // NOTE that this could be used for general float to float, but right now hard-coding year-as-int to float
            const auto & key = entry.first;
            tStringFloatMapConfigType * pSFMap = entry.second;
            const auto& tvcs_jo = json_cast<const json::Object&>( (*inputJson)[key] );
            for( auto data = tvcs_jo.Begin();
                      data != tvcs_jo.End();
                      ++data )
            {
                auto tvcs = inputJson->As< json::Object >()[ key ]; 
                float value = (float) ((json::QuickInterpreter( tvcs ))[ data->name ].As<json::Number>());
                LOG_DEBUG_F( "Inserting string %s and value %f into map.\n", data->name.c_str(), value );
                pSFMap->insert( std::make_pair( data->name, value ) );
            }
        }

        return true;
    }

    /*QuickBuilder JsonConfigurable::GetSchema()
    {
        return QuickBuilder( jsonSchemaBase );
    }*/

    std::set< std::string > JsonConfigurable::missing_parameters_set;

    JsonConfigurable::name2CreatorMapType&
    JsonConfigurable::get_registration_map()
    {
        static JsonConfigurable::name2CreatorMapType name2CreatorMap;
        return name2CreatorMap;
    }
    
    JsonConfigurable::Registrator::Registrator( const char* classname, get_schema_funcptr_t gs_callback )
    {
        const std::string stored_class_name = std::string( classname );
        get_registration_map()[ stored_class_name ] = gs_callback;
    }

    // IJsonSerializable Interfaces Implementation
    void JsonConfigurable::JSerialize( IJsonObjectAdapter* root, JSerializer* helper ) const
    {
        throw NotYetImplementedException( __FILE__, __LINE__, __FUNCTION__, "Nothing to serialize because IJsonSerializable has to be implemented by each individual class for actual serialization." );
    }

    void JsonConfigurable::JDeserialize( IJsonObjectAdapter* root, JSerializer* helper )
    {
        throw NotYetImplementedException( __FILE__, __LINE__, __FUNCTION__, "Nothing to deserialize because IJsonSerializable has to be implemented by each individual class for actual deserialization." );
    }

}