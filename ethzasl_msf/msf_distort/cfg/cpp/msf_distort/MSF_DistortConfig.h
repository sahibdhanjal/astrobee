//#line 2 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the msf_distort package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __msf_distort__MSF_DISTORTCONFIG_H__
#define __msf_distort__MSF_DISTORTCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace msf_distort
{
  class MSF_DistortConfigStatics;
  
  class MSF_DistortConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(MSF_DistortConfig &config, const MSF_DistortConfig &max, const MSF_DistortConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const MSF_DistortConfig &config1, const MSF_DistortConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, MSF_DistortConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const MSF_DistortConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, MSF_DistortConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const MSF_DistortConfig &config) const = 0;
      virtual void getValue(const MSF_DistortConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T MSF_DistortConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (MSF_DistortConfig::* field);

      virtual void clamp(MSF_DistortConfig &config, const MSF_DistortConfig &max, const MSF_DistortConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const MSF_DistortConfig &config1, const MSF_DistortConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, MSF_DistortConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const MSF_DistortConfig &config) const
      {
        nh.SetStateCovariancearam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, MSF_DistortConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const MSF_DistortConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const MSF_DistortConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, MSF_DistortConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); i++)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;
        
        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }
      
      virtual void updateParams(boost::any &cfg, MSF_DistortConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->SetStateCovariancearams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<MSF_DistortConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void SetStateCovariancearams(MSF_DistortConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = params.begin(); i != params.end(); i++)
      {
        boost::any val;
        (*i)->getValue(config, val);

        if("publish_pose"==(*i)->name){publish_pose = boost::any_cast<bool>(val);}
        if("publish_position"==(*i)->name){publish_position = boost::any_cast<bool>(val);}
      }
    }

    bool publish_pose;
bool publish_position;

    bool state;
    std::string name;

    
}groups;



//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      bool publish_pose;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      bool publish_position;
//#line 255 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("MSF_DistortConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const MSF_DistortConfig &__max__ = __getMax__();
      const MSF_DistortConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const MSF_DistortConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const MSF_DistortConfig &__getDefault__();
    static const MSF_DistortConfig &__getMax__();
    static const MSF_DistortConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const MSF_DistortConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void MSF_DistortConfig::ParamDescription<std::string>::clamp(MSF_DistortConfig &config, const MSF_DistortConfig &max, const MSF_DistortConfig &min) const
  {
    return;
  }

  class MSF_DistortConfigStatics
  {
    friend class MSF_DistortConfig;
    
    MSF_DistortConfigStatics()
    {
MSF_DistortConfig::GroupDescription<MSF_DistortConfig::DEFAULT, MSF_DistortConfig> Default("Default", "", 0, 0, true, &MSF_DistortConfig::groups);
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __min__.publish_pose = 0;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __max__.publish_pose = 1;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __default__.publish_pose = 1;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(MSF_DistortConfig::AbstractParamDescriptionConstPtr(new MSF_DistortConfig::ParamDescription<bool>("publish_pose", "bool", 1, "enable pose republishing", "", &MSF_DistortConfig::publish_pose)));
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(MSF_DistortConfig::AbstractParamDescriptionConstPtr(new MSF_DistortConfig::ParamDescription<bool>("publish_pose", "bool", 1, "enable pose republishing", "", &MSF_DistortConfig::publish_pose)));
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __min__.publish_position = 0;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __max__.publish_position = 1;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __default__.publish_position = 1;
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(MSF_DistortConfig::AbstractParamDescriptionConstPtr(new MSF_DistortConfig::ParamDescription<bool>("publish_position", "bool", 1, "enable position republishing", "", &MSF_DistortConfig::publish_position)));
//#line 259 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(MSF_DistortConfig::AbstractParamDescriptionConstPtr(new MSF_DistortConfig::ParamDescription<bool>("publish_position", "bool", 1, "enable position republishing", "", &MSF_DistortConfig::publish_position)));
//#line 233 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      Default.convertParams();
//#line 233 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator.py"
      __group_descriptions__.push_back(MSF_DistortConfig::AbstractGroupDescriptionConstPtr(new MSF_DistortConfig::GroupDescription<MSF_DistortConfig::DEFAULT, MSF_DistortConfig>(Default)));
//#line 390 "/home/slynen/Documents/projects/ros/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<MSF_DistortConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<MSF_DistortConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<MSF_DistortConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    MSF_DistortConfig __max__;
    MSF_DistortConfig __min__;
    MSF_DistortConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const MSF_DistortConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static MSF_DistortConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &MSF_DistortConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const MSF_DistortConfig &MSF_DistortConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const MSF_DistortConfig &MSF_DistortConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const MSF_DistortConfig &MSF_DistortConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<MSF_DistortConfig::AbstractParamDescriptionConstPtr> &MSF_DistortConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<MSF_DistortConfig::AbstractGroupDescriptionConstPtr> &MSF_DistortConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const MSF_DistortConfigStatics *MSF_DistortConfig::__get_statics__()
  {
    const static MSF_DistortConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = MSF_DistortConfigStatics::get_instance();
    
    return statics;
  }

//#line 42 "../cfg/parameters_distort.cfg"
      const int MSF_Distort_MISC = 1;
}

#endif // __MSF_DISTORTRECONFIGURATOR_H__
