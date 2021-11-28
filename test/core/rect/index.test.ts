import { Size } from '../../../index'

describe('[core] Size', () => {
  describe('constructor', () => {
    it('initializes from empty constructor', () => {
      const size = new Size()

      expect(size.width).toStrictEqual(0)
      expect(size.height).toStrictEqual(0)
    })

    it('initializes from numbers', () => {
      const size = new Size(10, 20)

      expect(size.width).toStrictEqual(10)
      expect(size.height).toStrictEqual(20)
    })
  })
})
