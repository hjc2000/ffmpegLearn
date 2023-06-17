#pragma once

template <class T>
class Wraper
{
public:
	virtual T *operator()(void)
	{
		return m_pWrapedObj;
	}

	virtual operator T **()
	{
		return &m_pWrapedObj;
	}

	virtual operator T *()
	{
		return m_pWrapedObj;
	}

	T *m_pWrapedObj = nullptr;
};