#include <string>

class Base3DObject
{
public:
	Base3DObject()
		:buffer_(nullptr), buffer_len_(0)
	{

	}
	~Base3DObject()
	{
		delete buffer_;
	}

	Base3DObject(const Base3DObject& other)
		:buffer_len_(other.buffer_len_), name_(other.name_)	// ,buffer_(other.buffer_) Ç³¿½±´
	{
		buffer_ = new unsigned short(*other.buffer_);		// Éî¿½±´
	}
	Base3DObject(Base3DObject&& other) noexcept
	{
		buffer_ = other.buffer_;
		other.buffer_ = nullptr;	// ·ÀÖ¹Ðü¿ÕÖ¸Õë
		buffer_len_ = other.buffer_len_;
		name_ = other.name_;
	}

	Base3DObject(unsigned short* buffer, unsigned int buffer_len, const std::string& name)
		:buffer_(buffer), buffer_len_(buffer_len), name_(name)
	{
	}
	
	const Base3DObject& operator=(const Base3DObject& other)
	{
		if (this != &other)
		{
			buffer_ = other.buffer_;
			buffer_len_ = other.buffer_len_;
			name_ = other.name_;
		}
		return *this;
	}
	const Base3DObject& operator=(Base3DObject& other) noexcept
	{
		if (this != &other)
		{
			buffer_ = other.buffer_;
			buffer_len_ = other.buffer_len_;
			name_ = other.name_;
		}
		return *this;
	}

protected:
	virtual void Copy(const Base3DObject& other) final
	{
		*this->buffer_ = *other.buffer_;
		this->buffer_len_ = other.buffer_len_;
		this->name_ = other.name_;
	}
	virtual void Move(Base3DObject&& other) final
	{
		*this->buffer_ = *other.buffer_;
		this->buffer_len_ = std::move(other.buffer_len_);
		this->name_ = std::move(other.name_);
	}

private:
	unsigned short* buffer_;
	unsigned int buffer_len_;
	std::string name_;
};