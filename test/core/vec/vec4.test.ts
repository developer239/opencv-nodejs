import { Vec4 } from '../../../index'

describe('[core] Vec4', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Vec4(5, 4, 3, 2)

      expect(point.x).toStrictEqual(5)
      expect(point.y).toStrictEqual(4)
      expect(point.z).toStrictEqual(3)
      expect(point.w).toStrictEqual(2)
    })
  })
})
