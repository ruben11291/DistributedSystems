// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `Cannon.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <Cannon.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __Cannon__Collector__injectSubmatrix_name = "injectSubmatrix";

const ::std::string __Cannon__Processor__init_name = "init";

const ::std::string __Cannon__Processor__injectMatrix_name = "injectMatrix";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::Cannon::upCast(::IceProxy::Cannon::Collector* p) { return p; }

void
::IceProxy::Cannon::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::Cannon::Collector>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Cannon::Collector;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::Cannon::Collector::injectSubmatrix(::Ice::Int row, ::Ice::Int col, ::Ice::Int order, const ::Cannon::Matrix& m, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __Cannon__Collector__injectSubmatrix_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Cannon::Collector* __del = dynamic_cast< ::IceDelegate::Cannon::Collector*>(__delBase.get());
            __del->injectSubmatrix(row, col, order, m, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::Cannon::Collector::begin_injectSubmatrix(::Ice::Int row, ::Ice::Int col, ::Ice::Int order, const ::Cannon::Matrix& m, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Cannon__Collector__injectSubmatrix_name, __del, __cookie);
    try
    {
        __result->__prepare(__Cannon__Collector__injectSubmatrix_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(row);
        __os->write(col);
        __os->write(order);
        __os->write(m);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::Cannon::Collector::end_injectSubmatrix(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Cannon__Collector__injectSubmatrix_name);
}

const ::std::string&
IceProxy::Cannon::Collector::ice_staticId()
{
    return ::Cannon::Collector::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Cannon::Collector::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Cannon::Collector);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Cannon::Collector::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Cannon::Collector);
}

::IceProxy::Ice::Object*
IceProxy::Cannon::Collector::__newInstance() const
{
    return new Collector;
}
::IceProxy::Ice::Object* ::IceProxy::Cannon::upCast(::IceProxy::Cannon::Processor* p) { return p; }

void
::IceProxy::Cannon::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::Cannon::Processor>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Cannon::Processor;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::Cannon::Processor::init(::Ice::Int row, ::Ice::Int col, const ::Cannon::ProcessorPrx& up, const ::Cannon::ProcessorPrx& left, ::Ice::Int order, const ::Cannon::CollectorPrx& target, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __Cannon__Processor__init_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Cannon::Processor* __del = dynamic_cast< ::IceDelegate::Cannon::Processor*>(__delBase.get());
            __del->init(row, col, up, left, order, target, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::Cannon::Processor::begin_init(::Ice::Int row, ::Ice::Int col, const ::Cannon::ProcessorPrx& up, const ::Cannon::ProcessorPrx& left, ::Ice::Int order, const ::Cannon::CollectorPrx& target, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Cannon__Processor__init_name, __del, __cookie);
    try
    {
        __result->__prepare(__Cannon__Processor__init_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(row);
        __os->write(col);
        __os->write(up);
        __os->write(left);
        __os->write(order);
        __os->write(target);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::Cannon::Processor::end_init(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Cannon__Processor__init_name);
}

void
IceProxy::Cannon::Processor::injectMatrix(const ::Cannon::Matrix& a, const ::Cannon::Matrix& b, ::Ice::Int step, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __Cannon__Processor__injectMatrix_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Cannon::Processor* __del = dynamic_cast< ::IceDelegate::Cannon::Processor*>(__delBase.get());
            __del->injectMatrix(a, b, step, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::Cannon::Processor::begin_injectMatrix(const ::Cannon::Matrix& a, const ::Cannon::Matrix& b, ::Ice::Int step, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Cannon__Processor__injectMatrix_name, __del, __cookie);
    try
    {
        __result->__prepare(__Cannon__Processor__injectMatrix_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(a);
        __os->write(b);
        __os->write(step);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::Cannon::Processor::end_injectMatrix(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Cannon__Processor__injectMatrix_name);
}

const ::std::string&
IceProxy::Cannon::Processor::ice_staticId()
{
    return ::Cannon::Processor::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Cannon::Processor::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Cannon::Processor);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Cannon::Processor::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Cannon::Processor);
}

::IceProxy::Ice::Object*
IceProxy::Cannon::Processor::__newInstance() const
{
    return new Processor;
}

void
IceDelegateM::Cannon::Collector::injectSubmatrix(::Ice::Int row, ::Ice::Int col, ::Ice::Int order, const ::Cannon::Matrix& m, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Cannon__Collector__injectSubmatrix_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(row);
        __os->write(col);
        __os->write(order);
        __os->write(m);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Cannon::Processor::init(::Ice::Int row, ::Ice::Int col, const ::Cannon::ProcessorPrx& up, const ::Cannon::ProcessorPrx& left, ::Ice::Int order, const ::Cannon::CollectorPrx& target, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Cannon__Processor__init_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(row);
        __os->write(col);
        __os->write(up);
        __os->write(left);
        __os->write(order);
        __os->write(target);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Cannon::Processor::injectMatrix(const ::Cannon::Matrix& a, const ::Cannon::Matrix& b, ::Ice::Int step, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Cannon__Processor__injectMatrix_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(a);
        __os->write(b);
        __os->write(step);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::Cannon::Collector::injectSubmatrix(::Ice::Int row, ::Ice::Int col, ::Ice::Int order, const ::Cannon::Matrix& m, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int __p_row, ::Ice::Int __p_col, ::Ice::Int __p_order, const ::Cannon::Matrix& __p_m, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_row(__p_row),
            _m_col(__p_col),
            _m_order(__p_order),
            _m_m(__p_m)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Cannon::Collector* servant = dynamic_cast< ::Cannon::Collector*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->injectSubmatrix(_m_row, _m_col, _m_order, _m_m, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int _m_row;
        ::Ice::Int _m_col;
        ::Ice::Int _m_order;
        const ::Cannon::Matrix& _m_m;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Cannon__Collector__injectSubmatrix_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(row, col, order, m, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Cannon::Processor::init(::Ice::Int row, ::Ice::Int col, const ::Cannon::ProcessorPrx& up, const ::Cannon::ProcessorPrx& left, ::Ice::Int order, const ::Cannon::CollectorPrx& target, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int __p_row, ::Ice::Int __p_col, const ::Cannon::ProcessorPrx& __p_up, const ::Cannon::ProcessorPrx& __p_left, ::Ice::Int __p_order, const ::Cannon::CollectorPrx& __p_target, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_row(__p_row),
            _m_col(__p_col),
            _m_up(__p_up),
            _m_left(__p_left),
            _m_order(__p_order),
            _m_target(__p_target)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Cannon::Processor* servant = dynamic_cast< ::Cannon::Processor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->init(_m_row, _m_col, _m_up, _m_left, _m_order, _m_target, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int _m_row;
        ::Ice::Int _m_col;
        const ::Cannon::ProcessorPrx& _m_up;
        const ::Cannon::ProcessorPrx& _m_left;
        ::Ice::Int _m_order;
        const ::Cannon::CollectorPrx& _m_target;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Cannon__Processor__init_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(row, col, up, left, order, target, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Cannon::Processor::injectMatrix(const ::Cannon::Matrix& a, const ::Cannon::Matrix& b, ::Ice::Int step, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Cannon::Matrix& __p_a, const ::Cannon::Matrix& __p_b, ::Ice::Int __p_step, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_a(__p_a),
            _m_b(__p_b),
            _m_step(__p_step)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Cannon::Processor* servant = dynamic_cast< ::Cannon::Processor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->injectMatrix(_m_a, _m_b, _m_step, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Cannon::Matrix& _m_a;
        const ::Cannon::Matrix& _m_b;
        ::Ice::Int _m_step;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Cannon__Processor__injectMatrix_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(a, b, step, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* Cannon::upCast(::Cannon::Collector* p) { return p; }

namespace
{
const ::std::string __Cannon__Collector_ids[2] =
{
    "::Cannon::Collector",
    "::Ice::Object"
};

}

bool
Cannon::Collector::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Cannon__Collector_ids, __Cannon__Collector_ids + 2, _s);
}

::std::vector< ::std::string>
Cannon::Collector::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Cannon__Collector_ids[0], &__Cannon__Collector_ids[2]);
}

const ::std::string&
Cannon::Collector::ice_id(const ::Ice::Current&) const
{
    return __Cannon__Collector_ids[0];
}

const ::std::string&
Cannon::Collector::ice_staticId()
{
    return __Cannon__Collector_ids[0];
}

::Ice::DispatchStatus
Cannon::Collector::___injectSubmatrix(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Int row;
    ::Ice::Int col;
    ::Ice::Int order;
    ::Cannon::Matrix m;
    __is->read(row);
    __is->read(col);
    __is->read(order);
    __is->read(m);
    __inS.endReadParams();
    injectSubmatrix(row, col, order, m, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __Cannon__Collector_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "injectSubmatrix"
};

}

::Ice::DispatchStatus
Cannon::Collector::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__Cannon__Collector_all, __Cannon__Collector_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Cannon__Collector_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___injectSubmatrix(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Cannon::Collector::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
Cannon::Collector::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
Cannon::__patch(CollectorPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::Cannon::CollectorPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::Cannon::Collector::ice_staticId(), v);
    }
}

::Ice::Object* Cannon::upCast(::Cannon::Processor* p) { return p; }

namespace
{
const ::std::string __Cannon__Processor_ids[2] =
{
    "::Cannon::Processor",
    "::Ice::Object"
};

}

bool
Cannon::Processor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Cannon__Processor_ids, __Cannon__Processor_ids + 2, _s);
}

::std::vector< ::std::string>
Cannon::Processor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Cannon__Processor_ids[0], &__Cannon__Processor_ids[2]);
}

const ::std::string&
Cannon::Processor::ice_id(const ::Ice::Current&) const
{
    return __Cannon__Processor_ids[0];
}

const ::std::string&
Cannon::Processor::ice_staticId()
{
    return __Cannon__Processor_ids[0];
}

::Ice::DispatchStatus
Cannon::Processor::___init(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Int row;
    ::Ice::Int col;
    ::Cannon::ProcessorPrx up;
    ::Cannon::ProcessorPrx left;
    ::Ice::Int order;
    ::Cannon::CollectorPrx target;
    __is->read(row);
    __is->read(col);
    __is->read(up);
    __is->read(left);
    __is->read(order);
    __is->read(target);
    __inS.endReadParams();
    init(row, col, up, left, order, target, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Cannon::Processor::___injectMatrix(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Cannon::Matrix a;
    ::Cannon::Matrix b;
    ::Ice::Int step;
    __is->read(a);
    __is->read(b);
    __is->read(step);
    __inS.endReadParams();
    injectMatrix(a, b, step, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __Cannon__Processor_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "init",
    "injectMatrix"
};

}

::Ice::DispatchStatus
Cannon::Processor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__Cannon__Processor_all, __Cannon__Processor_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Cannon__Processor_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___init(in, current);
        }
        case 5:
        {
            return ___injectMatrix(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Cannon::Processor::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
Cannon::Processor::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
Cannon::__patch(ProcessorPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::Cannon::ProcessorPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::Cannon::Processor::ice_staticId(), v);
    }
}