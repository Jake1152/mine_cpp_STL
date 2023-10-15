
// default (1)	
namespace mine
{
    template<typename U>
    class allocator
    {
        allocator() throw();
        // copy (2)	
        allocator (const allocator& alloc) throw();
        template <typename U>  allocator (const allocator<U>& alloc) throw();
    };
}